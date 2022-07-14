#include<cstring>
#include<string>
#include <iostream>
using namespace std;
const int Maxsize=100;
struct BigNumber
{
    int d[Maxsize];
    int length;
BigNumber()
{
    memset(d,0,sizeof(d));
    length=0;
}
};
BigNumber change (string str)
{
  BigNumber a;
    a.length=str.length();
    for (int  i = 0; i < a.length; i++)
    {
        a.d[i]=str[a.length-i-1]-'0';
    }
    return a;
};
class Number
{
    private:
    BigNumber a;
    BigNumber b;
public: 
    Number(string str1, string str2);
    BigNumber NumberPluse()
{
    BigNumber c;
    int flag=0;
    for (int  i = 0; i < a.length||i<b.length; i++)
    {
        int temp=a.d[i]+b.d[i]+flag;
        c.d[c.length++]=temp%10;
        flag=temp/10;
    }
    if(flag!=0)
    {
        c.d[c.length++]=flag;
    }
    return c;
};

BigNumber NumberMinus()
{
    BigNumber c;
    for (int i = 0; i < a.length||i<b.length; i++)
    {
        if (a.d[i]<b.d[i])
        {
            a.d[i+1]--;
            a.d[i]+=10;
        }
        c.d[c.length++]=a.d[i]-b.d[i];
    }
    while (c.length-1>=1 && c.d[c.length-1]==0)
    {
        c.length--;
    }
    return c;
};
int NumberDivide(int a[],int b[]);

};
Number::Number(string str1, string str2)
{
    a=change (str1);
    b=change (str2);
};
void print (BigNumber a)
{
    for (int i = a.length-1; i >= 0; i--)
    {
        cout<<a.d[i];
    }
};
int main()
{
    int n;
    string str1,str2;
    cin>>n;
    for(int i=0;i<n;i++)
    {
    cin>>str1>>str2;
    Number m{str1,str2};
    print(m.NumberMinus());
    cout<<endl;
    }
    system("pause");
    return 0;
}