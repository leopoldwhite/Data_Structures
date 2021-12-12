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

void Merge(int SR[],int TR[],int i,int m,int n)
{
    int j,k,l;
    for(j=m+1,k=i;i<=m&&j<=n;k++)
    {
        if(SR[i]<SR[j]) TR[k]=SR[i++];
        else TR[k]=SR[j++];
    }
    if(i<=m)
    {
        for(l=0;l<=m-i;l++)
            TR[k+l]=SR[i+l];
    }
    if(j<=n)
    {
        for(l=0;l<n-j;l++)
            TR[k+l]=SR[j+l];
    }
}

void Msort(int SR[],int TR1[],int s,int t)
{
    int m;
    int TR2[MAXSIZE+1];
    if(s==t)
        TR1[s]=SR[s];
    else
    {
        m=(s+t)/2;
        Msort(SR,TR2,s,m);
        Msort(SR,TR2,m+1,t);
        Merge(TR2,TR1,s,m,t);
    }
    
}

void MergeSort(SqList *L)
{
    Msort(L->r,L->r,1,L->length);
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
    MergeSort(L);
    for(i=1;i<L->length+1;i++)
    {
        cout<<L->r[i]<<" ";
    }
    return 0;
}