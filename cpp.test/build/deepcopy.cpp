#include<iostream>
using namespace std;
class Person
{    
public:
     Person()
 {     cout<<"Person call to use"<< endl ;}
     Person(int  age ,int height )
 {   cout<<"Person have parameter call to use"<< endl ;
     m_Age=age;
     m_Height=new int(height); 
 }
    Person(const Person &p)
    {
        cout <<"copy"<<endl;
        m_Age=p.m_Age;
        m_Height= new int (*p.m_Height);

    }
    ~Person()
    { cout<<"Person delate call to use"<< endl ;
       if (m_Height != NULL)
       {
           delete m_Height;
       }
       
    }
    int m_Age;
    int* m_Height;
};

void test ()
{
    Person p(18 , 180);
    Person p2(p);
    cout<<"p's age is:"<<p.m_Age<<"height is"<<*p.m_Height<<endl;
    cout<<"p2's age is :"<<p2.m_Age<<"height is"<<*p2.m_Height<<endl;

}


int main()
{
   test();
    system("pause");
    return 0;
}