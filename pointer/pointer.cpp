#include<iostream>
using namespace std;
int main()
{
    char *p1[2]={"abcd","ABCD"};
    cout<<*(*(p1+1)+2)<<endl;
    cout<<p1[1][2]<<endl;
    int a[][4]={1,2,3,4,5,6,7,8,9,10,11,12};
    int (*p2)[4];
    p2=a;
    cout<<p2[2][3]<<endl;
    cout<<*(*(p2+2)+3)<<endl;
    return 0;
}