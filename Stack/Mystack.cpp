#include<iostream>
using namespace std;
const int StackSize =10;

template<class Datatype>
class Seqstack
{
public:
    Seqstack(){top=-1;}
    ~Seqstack(){}
    void Push(Datatype x);
    Datatype Pop();
    Datatype Gettop(){if(top!=-1) return data[top];}
    int Empty(){if(top==-1) return 1;else return 0;}
private:
    Datatype data[StackSize];
    int top;
};

template<class Datatype>
void Seqstack<Datatype>::Push(Datatype x)
{
    if (top==StackSize-1) throw "overflow";
    data[++top]=x;
}

template<class Datatype>
Datatype Seqstack<Datatype>::Pop()
{
    if (top==-1) throw "underflow";
    Datatype x =data[top--];
    return x;
}

int main()
{
    Seqstack<int> s;
    cout<<s.Empty()<<endl;
    for (int i=0;i<10;i++)
    {
        s.Push(i);
        cout<<s.Gettop()<<" ";
    }
    cout<<endl;
    for (int i=0;i<10;i++)
    {
        cout<<s.Pop()<<" ";
    }
    return 0;
}