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

void ShellSort(SqList *L)
{
    int i,j,k=0;
    int increment=L->length;
    do
    {  
        increment=increment/3+1;
        for(i=increment+1;i<=L->length;i++)
        {
            if(L->r[i]<L->r[i-increment])
            {
                L->r[0]=L->r[i];
                for(j=i-increment;j>0&&L->r[0]<L->r[j];j-=increment)
                    L->r[j+increment]=L->r[j];
                L->r[j+increment]=L->r[0];
            }
        }
    } while (increment>1);
    
    
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
    ShellSort(L);
    for(i=1;i<L->length+1;i++)
    {
        cout<<L->r[i]<<" ";
    }
    return 0;
}