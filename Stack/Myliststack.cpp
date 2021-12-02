#include<iostream>
using namespace std;

template<class t>
class Linkstack
{
public:
    typedef struct node
    {
        t data;
        node *next;
    }Node;
    Linkstack(){top =NULL;}
    ~Linkstack();
    void Push(t x);
    t Pop();
    t Gettop(){if(top!=NULL) return top->data;}
    int Empty(){if (top==NULL) return 1;else return 0;}
private:
    Node *top;
};

template<class t>
Linkstack<t>::~Linkstack()
{
    while(top!=NULL)
    {
        Node *p =top;
        top =top->next;
        delete p;
    }
}

template<class t>
void Linkstack<t>::Push(t x)
{
    Node *s = new Node;
    s->next=top;
    s->data=x;
    top=s;
}

template<class t>
t Linkstack<t>::Pop()
{
    if(top==NULL) throw "underflow";
    t x=top->data;
    Node *p=top;
    top=top->next;
    delete p;
    return x;
}

int main()
{
    Linkstack<int> s;
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