#include<iostream>
using namespace std;

const int Stacksize=100;

template<class t>
class Bothstack
{
public:
    Bothstack(){top1=-1;top2=Stacksize;}
    ~Bothstack(){}
    void Push(int i,t x);
    t Pop(int i);
    t Gettop(int i);
    int Empty(int i);
private:
    t data[Stacksize];
    int top1,top2;
};

template<class t>
void Bothstack<t>::Push(int i,t x)
{
    if (top1==top2-1) throw "Overflow";
    if(i==1) data[++top1]=x;
    if(i==2) data[--top2]=x;
}

template<typename t>
t Bothstack<t>::Pop(int i)
{
    if (i==1 && top1==-1||i==2 && top2==Stacksize) throw "underflow";
    if (i==1) return data[top1--];
    if (i==2) return data[top2++];
}

template<class t>
t Bothstack<t>::Gettop(int i)
{
    if(i==1) return data[top1];
    if(i==2) return data[top2];
}

template<class t>
int Bothstack<t>::Empty(int i)
{
    if(i==1)
    {
        if (top1==-1) return 1;
        else return 0;
    }
    if(i==2)
    {
        if (top2==Stacksize) return 1;
        else return 0;
    }
}

int main()
{
    Bothstack<int> s;
    cout<<s.Empty(1)<<" "<<s.Empty(2)<<endl;
    for(int i=0;i<10;i++)
    {
        s.Push(1,i);
        cout<<s.Gettop(1)<<" ";
    }
    for(int i=0;i<10;i++)
    {
        s.Push(2,i);
        cout<<s.Gettop(2)<<" ";
    }
    cout<<endl;
    for(int i=0;i<10;i++)
    {
        cout<<s.Pop(1)<<" "<<s.Pop(2)<<" ";
    }

    return 0;
}