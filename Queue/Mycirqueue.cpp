#include<iostream>
using namespace std;

const int Queuesize=100;
template<class t>
class Cirqueue
{
public:
    Cirqueue(){front=rear=Queuesize-1;}
    ~Cirqueue(){}
    void Enqueue(t x);
    t Dequeue();
    t Getqueue();
    int Empty(){if(front=rear) return 1;else return 0;}
    int Length(){return (rear-front+Queuesize)%Queuesize;}
private:
    t data[Queuesize];
    int front,rear;
};

template<class t>
void Cirqueue<t>::Enqueue(t x)
{
    if((rear+1)%Queuesize==front) throw "overflow";
    data[rear]=x;
    rear=(rear+1)%Queuesize;
}

template<class t>
t Cirqueue<t>::Dequeue()
{
    t x;
    if(rear==front) throw "underflow";
    x=front;
    front=(front+1) %Queuesize;
    return data[x];
}

template<class t>
t Cirqueue<t>::Getqueue()
{
    if (rear==front) throw " underflow";
    return data[front];
}

int main()
{
    Cirqueue<int> q;
    cout<<q.Empty()<<endl;
    for(int i=0;i<10;i++)
    {
        q.Enqueue(i);
    }
    cout<<q.Getqueue()<<endl;
    cout<<q.Length()<<endl;
    cout<<q.Dequeue()<<endl;
    cout<<q.Dequeue()<<endl;
    return 0;
}