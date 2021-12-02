#include<iostream>
#include<string>
using namespace std;

struct Node
{
    long long int ID;
    string Name;
    int G1,G2,G3;
    int Sum;
    Node *next,*prior;
};

class GradeManagement
{
public:
    GradeManagement();
    ~GradeManagement();
    void Add(long long int id,int g1,int g2,int g3,string name);
    void Modify(long long int id,int g1,int g2,int g3,string name);
    void Delete(long long int id);
    void ShowByID(long long int id);
    void ShowByName(string name);
    void ShowAllByID();
    void ShowAllReverse();
    void ShowAllBySum(GradeManagement origin);
private:
    void ShowInfo(Node *p);
    Node *first;
};

GradeManagement::GradeManagement()
{
    first=new Node;
    first->next=NULL;
    first->prior=first;
    first->ID=0;
    first->Name="";
}

GradeManagement::~GradeManagement()
{
    while(first!=NULL)
    {
        Node *q=first;
        first=first->next;
        delete q;
    }
}

void GradeManagement::Add(long long int id,int g1,int g2,int g3,string name)
{
    Node *p=first;
    Node *s=new Node;
    s->ID=id;
    s->G1=g1;
    s->G2=g2;
    s->G3=g3;
    s->Name=name;
    s->Sum=g1+g2+g3;
    while(p->next!=NULL&&(s->ID)>(p->next->ID))
    {
        p=p->next;
    }
    s->next=p->next;
    s->prior=p;
    if(p->next==NULL)
    {
        p->next=s;
    }
    else
    {
        p->next->prior=s;
        p->next=s;
    }
}

void GradeManagement::Modify(long long int id,int g1,int g2,int g3,string name)
{
    Node *p=first;
    while(p!=NULL&&p->ID!=id)
    {
        p=p->next;
    }
    if(p==NULL) throw "Error";
    else
    {
        p->G1=g1;
        p->G2=g2;
        p->G3=g3;
        p->Name=name;
    }
}

void GradeManagement::Delete(long long int id)
{
    Node *p=first;
    while(p->next!=NULL&&p->next->ID!=id)
    {
        p=p->next;
    }
    if(p==NULL) throw "Error";
    else
    {
        Node *q=p->next;
        q->next->prior =q->prior;
        p->next=q->next;
        delete q;
    }
}

void  GradeManagement::ShowInfo(Node *p)
{
    cout<<"ID: "<<p->ID<<" ";
    cout<<"NAME: "<<p->Name<<" ";
    cout<<"GRADE1: "<<p->G1<<" ";
    cout<<"GRADE2: "<<p->G2<<" ";
    cout<<"GRADE3: "<<p->G3<<" ";
    cout<<endl;
}

void GradeManagement::ShowByID(long long int id)
{
    Node *p=first;
    while(p!=NULL&&p->ID!=id)
    {
        p=p->next;
    }
    if(p==NULL) throw "Error";
    else ShowInfo(p);
}

void GradeManagement::ShowByName(string name)
{
    Node *p=first;
    while(p!=NULL)
    {
        if(p->Name==name)
        {
            ShowInfo(p);
        }
        p=p->next;
    }
}

void GradeManagement::ShowAllByID()
{
    Node *p=first;
    while(p->next!=NULL)
    {
        p=p->next;
        ShowInfo(p);
    }
}

void GradeManagement::ShowAllReverse()
{
    Node *p=first;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    while(p->prior!=first)
    {
        ShowInfo(p);
        p=p->prior;
    }
    ShowInfo(p);
}

void GradeManagement::ShowAllBySum(GradeManagement origin)
{

}

int main()
{
    GradeManagement Grades;
    Grades.Add(10001,1,1,1,"wxz");
    Grades.Add(10002,2,2,2,"wxz");
    Grades.Add(10003,3,3,3,"wxz2");
    //Grades.ShowAllByID();
    //Grades.ShowAllReverse();
    //Grades.ShowByName("wxz");

    return 0;
}