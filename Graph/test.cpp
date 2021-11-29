#include<iostream>
#include<iomanip>
using namespace std;

struct stru
{
    int a;
};


void change(stru *s)
{
    s[0].a=1;
    s[1].a=2;
}

void f()
{
    stru s[10];
    change(s);
    cout<<s[0].a<<endl<<s[1].a;
}

int main()
{
    
    f();
    return 0;
}