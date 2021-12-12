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

int Partition(SqList *L,int low,int high)
{
    int pivotkey;
//midian-of-three
    int m=low+(high-low)/2;
    if(L->r[low]>L->r[high]) swap(L,low,high);
    if(L->r[m]>L->r[high]) swap(L,high,m);//将最大数放到最右边
    if(L->r[m]>L->r[low]) swap(L,m,low);//把剩下两个数的较大者（即中间值）放到最左边（作为pivot）

    pivotkey=L->r[low];
    while(low<high)
    {
        while(low<high&&L->r[high]>=pivotkey)
            high--;
        swap(L,low,high);
        while (low<high&&L->r[low]<=pivotkey)
            low++;
        swap(L,low,high);
    }
    return low;
}

void QSort(SqList *L,int low,int high)
{
    int pivot;
    if(low<high)
    {
        pivot=Partition(L,low,high);//选定一个关键字，想办法能将它放到一个位置使得左边的值都比它小，右边的值都比它大，这样的关键字成为pivot
        QSort(L,low,pivot-1);
        QSort(L,pivot+1,high);
    }
}

void QuickSort(SqList *L)
{
    QSort(L,1,L->length);
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
    QuickSort(L);
    for(i=1;i<L->length+1;i++)
    {
        cout<<L->r[i]<<" ";
    }
    return 0;
}