#include<iostream>
#include<string>
using namespace std;
class Phone
{
    public :
    Phone(string pName)
    {
        m_PName=pName;
    }
    string m_PName;
} ;

class Person
{
  public:
  //Phone m_Phone=pName;
  Person(string name , string pName):m_Name(name),m_Phone(pName)
  {
      
  }
  string m_Name;
  Phone m_Phone;
};
void test()
{
    Person p("zhang san","iphone max");
    cout<<p.m_Name<<" have "<<p.m_Phone.m_PName<<endl;//注意是p.m_Phone.m_PName
}
int main()
{
    test();
    system ("pause");
    return 0;
}

