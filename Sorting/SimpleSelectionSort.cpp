//通过n-i次关键字之间的比较，从n-i+1个记录中选出关键字最小的记录，并和第i个记录交换

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

void SelectSort(SqList *L)
{
    int i,j,min;
    for(i=1;i<L->length;i++)
    {
        min=i;
        for(j=i+1;j<=L->length;j++)
        {
            if(L->r[min]>L->r[j])
            {
                min=j;
            }
            if(min!=i) swap(L,i,min);
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
    SelectSort(L);
    for(i=1;i<L->length+1;i++)
    {
        cout<<L->r[i]<<" ";
    }
    return 0;
}