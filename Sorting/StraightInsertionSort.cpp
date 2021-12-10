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

void InsertSort(SqList *L)
{
    int i,j;
    for(i=2;i<=L->length;i++)
    {
        if(L->r[i]<L->r[i-1])
        {
            L->r[0]=L->r[i];
            for(j=i-1;L->r[j]>L->r[0];j--) L->r[j+1]=L->r[j];//从已经排序好的序列尾开始，比较缓冲区关键字和当前指针位置的关键字大小，将比缓冲区大的关键字全部后移一位，直至指针指向的关键字比缓冲区关键字小，循环结束，则指针指向的后一位置就是缓冲区关键字应该插入的位置
            L->r[j+1]=L->r[0];
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
    InsertSort(L);
    for(i=1;i<L->length+1;i++)
    {
        cout<<L->r[i]<<" ";
    }
    return 0;
}