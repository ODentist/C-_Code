#include <iostream>
using namespace std;
//引用变量
// int main(){
//     int a=3,&r=a;
//     cout<<a<<"\t"<<r<<endl;
//     r=5;
//     cout<<a<<"\t"<<r<<endl;
// }
//正常交换两个变量的值
// void swap(int a, int b){
//     int temp;
//     temp=a;
//     a=b;
//     b=temp;
// }
// int main(){
//     int a=5,b=3;
//     swap(a,b);
// }
//引用变量交换
void swap(int &a, int &b){
    int t =a;
    a=b;
    b=t;
}
int main(){
    int a=5,b=3;
    swap(a,b);
    cout<<a<<"\t"<<b<<endl;
    }