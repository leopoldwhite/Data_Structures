#include<iostream>
using namespace std;
#define MAXSIZE 10000

struct SqList
{
    int r[MAXSIZE+1];
    int length;
};

void swap(SqList *L,int i,int j)
{
    int temp=L->r[i];
    L->r[i]=L->r[j];
    L->r[j]=temp;
}

void BubbleSort(SqList *L)
{
    int i,j;
    for(i=1;i<L->length;i++)
    {
        for(j=L->length-1;j>=i;j--)
        {
            if(L->r[j]>L->r[j+1]) swap(L,j,j+1);
        }
    }
}

void BubbleSort2(SqList *L)//如果在某次循环中没有数据交换，则说明排序已经完成，则不需要继续循环
{
    int i,j;
    bool flag=true;
    for(i=1;i<L->length-1&&flag;i++)
    {
        flag=false;
        for(j=L->length-1;j>=i;j--)
        {
            if(L->r[j]>L->r[j+1])
            {
                swap(L,j,j+1);
                flag=true;
            }
        }
    }
}

int main()
{
    SqList *L=new SqList;
    int i;
    cin>>L->length;
    for(i=1;i<L->length+1;i++)
    {
        cin>>L->r[i];//9 9 8 7 6 5 4 3 2 1
    }
    BubbleSort(L);
    for(i=1;i<L->length+1;i++)
    {
        cout<<L->r[i]<<" ";
    }
    return 0;
}