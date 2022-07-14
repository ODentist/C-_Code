#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
void StrLength(string s1)
{
    int l;
    l=s1.length();
    cout<<"字符串长度为"<<l<<endl;
};
string Connect(string s1,string s2)
{
    string s=s1+s2;
    return s;
};
void Compare(string s1,string s2)
{
    int l1,l2;
    l1=s1.length();
    l2=s2.length();
    if (l1>l2)
    {
        cout<<"较长的为s1:"<<s1<<endl;
    }
    else
    {
        cout<<"较长的为s2:"<<s2<<endl;
    }
};
int main()
{
    string s1,s2,s;
    cout<<"输入字符串s1"<<endl;
    cin>>s1;
    StrLength(s1);
    cout<<"输入字符串s2"<<endl;
    cin>>s2;
    StrLength(s2);
    s=Connect(s1,s2);
    cout<<"合并后为"<<s<<endl;
    Compare(s1,s2);
    system("pause");
    return 0;
}