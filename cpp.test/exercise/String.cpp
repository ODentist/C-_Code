#include<iostream>
#include<malloc.h>
#include<cstring>
#include<cstdio>
using namespace std;
//动态字符串分配
int main(){
    char *s=(char *)malloc(12*sizeof(char));
    //指针自身 = (指针类型*）malloc（sizeof（指针类型）*数据数量）
    strcpy(s,"hello world");
    puts(s);
}