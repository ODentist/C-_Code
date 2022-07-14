#include<iostream>
using namespace std;
//左移运算符重载
class Person
{
public:
    //用成员函数重载左移运算符
    //不可行，因为会使cout在右侧
    
        int m_A;
        int m_B;

};
//只能利用全局函数重载左移前运算
ostream& operator<<(ostream &cout,Person &p)//cout为ostream类型，所以前置返回为ostream，又因为ostream的对象只能有一个，所以只能用&来传递地址

{
    cout<<"m_A="<<p.m_A<<" m_B="<<p.m_B<<endl;
    return cout;//返回cout，可以一直执行链式编程
}
void test()
{
    Person p;
    p.m_A=10;
    p.m_B=10;
    cout<<p<<endl;//重载<<符号


}
int main()
{
    test();
    system("pause");
    return 0;

}