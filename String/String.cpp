#include<iostream>
#include<string>
#include<cstring>
#include <algorithm>
using namespace std;
void S1();
void S2();
void S3();
void S4();

void S1()
{
    string str1="abdshjakfdfasf";
    string str2("abcd");
    string str3("0ABcd",1,4);
    string str4(10,'#');
    //string str5(str2,2);
    cout<<str1<<endl;
    cout<<str2<<endl;
    cout<<str3<<endl;
    cout<<str4<<endl;
    //cout<<str5<<endl;
}

void S2()
{
    string a("abcd");
    string b("Abcd");
    cout<<a.compare(b)<<endl;
    cout<<a.compare(1,3,b,1,3)<<endl;
    cout<<b.compare(a)<<endl;
}

void S3()
{
    string s;
    s.push_back('b');
    s.push_back('c');
    s.push_back('e');
    s.insert(0,"a");
    s.insert(3,"d");
    cout<<s<<endl;
}

void S4()
{
    string s1("abcd");
    string s2("efgh");
    cout<<s1+s2<<endl;
    s1.append(s2);
    s1.append("ijkl");
    cout<<s1<<endl;
}

void S5()
{
    string s="123456789";
    s.erase(8);//删除下标为8后的所有字符（含8）
    cout<<s<<endl;
    s="123456789";
    s.erase(1,7);
    cout<<s<<endl;
}

void S6()
{
    string s1("hello world");
    cout<<s1.size()<<endl;
    s1.replace(s1.size()-5,5,"china");
    cout<<s1<<endl;
    s1.replace(0,5,5,'h');
    cout<<s1<<endl;
}

void S7()
{
    string s("abcdef");
    for(int i=0;i<s.size();i++)
    {
        s[i]=toupper(s[i]);
    }
    cout<<s<<endl;
    transform(s.begin(),s.end(),s.begin(),::tolower);//s.begin()返回迭代器
    cout<<s<<endl;
}

void S8()
{
    string s("abcdefgabcdefg");
    string s2("cdef");
    cout<<s.find("bcd")<<endl;
    cout<<s.rfind("bcd")<<endl;
    cout<<s.find_first_of(s2)<<endl;

}

void S9()
{
    string s="sdajfwehiohgeuiw";
    sort(s.begin(),s.end());
    cout<<s<<endl;
}

void S10()
{
    string s1("0123456");
    string s2=s1.substr(2,5);
    cout<<s2<<endl;
}

void S11()
{
    char s[]="i,am,a,student.";
    const char *split=",.";
    char *p2=strtok(s,split);
    while(p2!=NULL)
    {
        cout<<p2<<" ";
        p2=strtok(NULL,split);
    }

}

int main()
{
    //S1();
    //S2();
    //S3();
    //S4();
    //S5();
    //S6();
    //S7();
    //S8();
    //S9();
    //S10();
    S11();
    return 0;
}
