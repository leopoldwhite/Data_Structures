#include<iostream>
using namespace std;
#define Link 0;
#define Thread 1;
int count=0;

template<class datatype>
struct BiNode
    {
        datatype data;
        BiNode<datatype> *lchild,*rchild;
        int LTag,RTag;
    };

BiNode<char> *pre=new BiNode<char>;

template<class datatype>
void CreateBiTree(BiNode<datatype>* &T)//传入原指针本身，对原指针进行修改
{
    datatype ch;
    cin>>ch;
    if(ch=='#') T=NULL;
    else
    {
        if(count!=0) T=new BiNode<datatype>;
        T->data =ch;
        T->LTag=Link;
        T->RTag=Link;
        count++;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}

template<class datatype>
void InThreading(BiNode<datatype>* T)
{
    if(T==NULL) return;
    InThreading(T->lchild);
    if(T->lchild==NULL)
    {
        T->LTag=Thread;
        T->lchild=pre;
    }
    if(pre->rchild==NULL) 
    {
        pre->RTag=Thread;
        pre->rchild=T;
    }
    pre=T;
    InThreading(T->rchild);
}

template<class datatype>
void PreOrderTraverse(BiNode<datatype> *T)
{
    if(T==NULL) return;
    cout<<T->data;
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}

template<class datatype>
void InOrderTraverse(BiNode<datatype> *T)
{
    if(T==NULL) return;
    InOrderTraverse(T->lchild);
    cout<<T->data;
    InOrderTraverse(T->rchild);
}

template<class datatype>
void PostOrderTraverse(BiNode<datatype> *T)
{
    if(T==NULL) return;
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    cout<<T->data;
}

template<class datatype>
void InOrderTraverse_Thr(BiNode<datatype> *T)
{
    BiNode<datatype> *p=T;
    while(p!=NULL)
    {
        while (p->LTag==0)
        {
            p=p->lchild;
        }
        cout<<p->data;
        while(p!=NULL&&p->RTag==1)
        {
            p=p->rchild;
            cout<<p->data;
        }
        p=p->rchild;
    }
}

int main()
{
    BiNode<char> *Tree=new BiNode<char>;
    CreateBiTree(Tree);// ABDH##I##E#J##CF##G##
    InThreading(Tree);
    InOrderTraverse_Thr(Tree);//HDIBEJAFCG
    return 0;
}

