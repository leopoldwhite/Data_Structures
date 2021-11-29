#include<iostream>
using namespace std;

template<class t>
class Linkqueue
{
public:
    typedef struct node
    {
        t data;
        node *next;
    }Node;
    Linkqueue();
    ~Linkqueue();
    void Enqueue(t x);
    t Dequeue();
    t Getqueue();
    int Empty(){if(front==rear) return 1;else return 0;}
private:
    Node *front,*rear;
};

template<class t>
Linkqueue<t>::Linkqueue()
{
    Node *s=new Node;
    s->next=NULL;
    front = rear =s;
}

template<class t>
Linkqueue<t>::~Linkqueue()
{
    while(front!=NULL)
    {
        Node *s=front;
        front=front->next;
        delete s;
    }
}

template<class t>
void Linkqueue<t>::Enqueue(t x)
{
    Node *s=new Node;
    s->data=x;
    s->next=NULL;
    rear->next=s;
    rear=s;
}

template<class t>
t Linkqueue<t>::Dequeue()
{
    if(rear==front) throw "underflow";
    Node *p = front->next;
    t x =p->data;
    front->next=p->next;
    if(rear==p) rear=front;
    delete p;
    return x;
}

template<class t>
t Linkqueue<t>::Getqueue()
{
    t x=front->next->data;
    return x;
}

int main()
{
    Linkqueue<int> q;
    cout<<q.Empty()<<endl;
    for (int i=0;i<10;i++)
    {
        q.Enqueue(i);
        cout<<q.Getqueue()<<endl;
        cout<<q.Dequeue()<<endl;
    }
    cout<<endl;

    return 0;
}