#include<iostream>
using namespace std;

const int Maxsize = 1000;

template<class Datatype>
class Staticlist
{
public:
    typedef struct
    {
        Datatype data;
        int next;
    }Node;
    Staticlist();
    Staticlist(Datatype a[],int n);
    ~Staticlist(){}
    int Length(){return length;}
    Datatype Get(int i);
    int Locate(Datatype x);
    void Insert(int i,Datatype x);
    Datatype Delete(int i);
    void Printlist();

private:
    Node Slist[Maxsize];
    int length;
    int avail;
};

template<class Datatype>
Staticlist<Datatype>::Staticlist()
{
    length=0;
    for(int i =1;i<Maxsize-1;i++)
    {
        Slist[i].next=i+1;
    }
    Slist[Maxsize-1].next=-1;
    Slist[0].next=-1;
    avail=1;
}

template<class Datatype>
Staticlist<Datatype>::Staticlist(Datatype a[], int n)
{
    length =n;
    avail=1;
    for (int i =0;i<Maxsize-1;i++)
    {
        Slist[i].next=i+1;
    }
    Slist[Maxsize-1].next=-1;
    Slist[0].next=avail;
    for(int j=avail;j<=n;j++)
    {
        Slist[j].data=a[j-1];
        Slist[j].next=j+1;
    }
    avail=Slist[n].next;
}

template<class Datatype>
Datatype Staticlist<Datatype>::Get(int i)
{
    int m =0;
    if(i>length||i<1) throw "location";
    else{
        for (int j=0;j<i;j++)
        {
            m=Slist[m].next;
        }
        return Slist[m].data;
    }
}

template<class Datatype>
int Staticlist<Datatype>::Locate(Datatype x)
{
    int m=0;
    for(int i=1;i<=length;i++)
    {
        m=Slist[m].next;
        if(Slist[m].data==x) {return i;}
    }
    return 0;
}

template<class Datatype>
void Staticlist<Datatype>::Insert(int i,Datatype x)
{
    if(length==Maxsize-2) throw "full";
    else if(i<1 || i>length+1) throw "location";
    else
    {
        int m=0;
        for (int j=0;j<i-1;j++)
        {
            m=Slist[m].next;
        }
        int t =avail;
        avail =Slist[avail].next;
        int s=Slist[m].next;
        Slist[m].next=t;
        Slist[t].next=s;
        Slist[t].data=x;
        length++;
    }
}

template<class Datatype>
Datatype Staticlist<Datatype>::Delete(int i)
{
    if(i<1||i>length) throw "location";
    else
    {
        int m=0;
        for (int j=0;j<i-1;j++)
        {
            m=Slist[m].next;
        }
        int t =Slist[m].next;
        Datatype temp =Slist[t].data;
        Slist[m].next =Slist[t].next;
        Slist[t].next=avail;
        avail=t;
        length--;
        return temp;
    }
}

template<class Datatype>
void Staticlist<Datatype>::Printlist()
{
    int m=Slist[0].next;
    for (int i=0;i<length;i++)
    {
        cout<<Slist[m].data<<" ";
        m=Slist[m].next;
    }
    cout<<endl;
}

int main()
{
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    Staticlist<int> s(a,10);
    s.Printlist();
    s.Insert(1,0);
    s.Printlist();
    s.Delete(1);
    s.Printlist();
    cout<<s.Locate(5)<<endl;
    cout<<s.Get(6)<<endl; 
    return 0;
}