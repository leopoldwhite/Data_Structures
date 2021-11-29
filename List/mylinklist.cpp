#include<iostream>
using namespace std;

template<class Datatype>
struct Node
{
    Datatype data;
    Node<Datatype> *next;
};

template<class Datatype>
class Linklist
{
    Node<Datatype> *first;
public:
    Linklist();
    Linklist(Datatype a[],int n);
    ~Linklist();
    int Length();
    Datatype Get(int i);
    int Locate(Datatype x);
    void Insert(int i,Datatype x);
    Datatype Delete(int i);
    void Printlist();
};

template<class Datatype>
Linklist<Datatype>::Linklist()
{
    first=new Node<Datatype>;
    first->next=NULL;
}

template<class Datatype>
Linklist<Datatype>::Linklist(Datatype a[],int n)
{
    first =new Node<Datatype>;
    Node<Datatype> *r=first;
    for (int i=0;i<n;i++)
    {
        Node<Datatype> *s=new Node<Datatype>;
        s->data=a[i];
        r->next=s;
        r=s;
    }
    r->next=NULL;
}

template<class Datatype>
Linklist<Datatype>::~Linklist()
{
    while(first!=NULL)
    {
        Node<Datatype> *q=first;
        first=first->next;
        delete q;
    }
}

template<class Datatype>
int Linklist<Datatype>::Length()
{
    Node<Datatype> *p=first->next;
    int count = 0;
    while (p!=NULL)
    {
        p=p->next;
        count++;
    }
    cout<<count<<endl;
    return count;
}

template<class Datatype>
Datatype Linklist<Datatype>::Get(int i)
{
    Node<Datatype> *p=first->next;
    int count=1;
    while(p!=NULL&&count<i)
    {
        p=p->next;
        count++;
    }
    if (p==NULL) throw "location";
    else return p->data;
}

template<class Datatype>
int Linklist<Datatype>::Locate(Datatype x)
{
    Node<Datatype> *p=first->next;
    int count=1;
    while (p!=NULL)
    {
        if (p->data==x) return count;
        p=p->next;
        count++;
    }
    return 0;
}

template<class Datatype>
void Linklist<Datatype>::Insert(int i, Datatype x)
{
    Node<Datatype> *p=first;
    int count=0;
    while(p!=NULL&&count<i-1)
    {
        p=p->next;
        count++;
    }
    if (p==NULL) throw "Location";
    else
    {
        Node<Datatype> *s=new Node<Datatype>;
        s->data=x;
        s->next=p->next;
        p->next=s;
    }
}

template<class Datatype>
Datatype Linklist<Datatype>::Delete(int i)
{
    Node<Datatype> *p=first;
    int count=0;
    while(p!=NULL&&count<i-1)
    {
        p=p->next;
        count++;
    }
    if (p==NULL||p->next==NULL) throw "location";
    else
    {
        Node<Datatype> *q=p->next;
        int x=q->data;
        p->next=q->next;
        delete q;
        return x;
    }
}

template<class Datatype>
void Linklist<Datatype>::Printlist()
{
    Node<Datatype> *p=first->next;
    while(p!=NULL)
    {
        cout<<p->data<<endl;
        p=p->next;
        
    }
}

int main()
{
    int a[8]={1,2,3,4,5,6,7,8};
    Linklist<int> list(a,8);
    list.Printlist();
    cout<<list.Get(6)<<endl;
    cin.get();
    return 0;
}