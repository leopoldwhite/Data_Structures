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

void HeapAdjust(SqList *L,int s,int m)
{
    int temp,j;
    temp=L->r[s];
    for(j=2*s;j<=m;j*=2)
    {
        if(j<m&&L->r[j]<L->r[j+1]) ++j;
        if(temp>=L->r[j]) break;
        L->r[s]=L->r[j];
        s=j;
    }
    L->r[s]=temp;
    
}

void HeapSort(SqList *L)
{
    int i;
    for(i=L->length/2;i>0;i--)
    {
        HeapAdjust(L,i,L->length);
    }
    for(i=L->length;i>1;i--)
    {
        swap(L,1,i);
        HeapAdjust(L,1,i-1);
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
    HeapSort(L);
    for(i=1;i<L->length+1;i++)
    {
        cout<<L->r[i]<<" ";
    }
    return 0;
}