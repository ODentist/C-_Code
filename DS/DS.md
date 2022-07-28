# 数据结构

## 第一章：绪论

### 1.1基本概念

1. 数据：数据是信息的载体，可以被计算机程序识别和处理的符号集合
2. 数据元素：数据元素的数据的基本单位，一个数据元素可以由若干个数据组成
2.2 数据项：是数据元素不可分割的最小单位
3. 数据对象：具有相同特征的数据元素的集合
4. 数据类型：一个值定义的集合和定义在此集合上的一组操作总称
5. 数据结构：相互存在一种或多种特定关系的数据元素集合

#### 1.1.2数据结构三要素

1. 数据的逻辑结构
![Image text](/DS/img/%E6%95%B0%E6%8D%AE%E7%9A%84%E9%80%BB%E8%BE%91%E7%BB%93%E6%9E%84%E5%88%86%E7%B1%BB%E5%9B%BE.PNG)
2. 数据的存储结构（物理结构）：
        2.1：顺序存储
        2.2：链式存储
        2.3：索引存储
        2.4：散列存储（哈希存储）
3. 数据的运算

#### extra1

1. 完整的数据结构可以由 ： 抽象数据类型 定义     不可以由 单一的数据元素，数据对象或数据关系定义
2. 有序表仅仅描述元素之间的逻辑关系，既可以是链式存储，也可以是顺序存储
3. 栈是一种抽象的数据类型，可以是顺序或链式，只表示逻辑结构，而循环队列是顺序表表示的队列属于存储结构
4. 数据的逻辑结构独立于其存储结构
5. 链式存储设计时，结点内的存储单元地址是连续的，结点与结点之间的存储地址可以是不连续的。

## 1.2 算法和算法评价

### 1.2.1算法的基本概念

 1. 算法是对特定问题求解步骤的一种描述，它是指令的有限序列，每条指令表示一条或多条操作。

 2. 算法的五个重要特征：1）有穷性 ， 2）确定性 ， 3）可行性 ， 4）输入 ， 5）输出
 3. 好的算法应该达到的目标：1） 正确性 ， 2）可读性 ， 3）健壮性 ， 4）效率与低存储量需求

### 1.2.2 算法效率的度量

1. 时间复杂度:
    设运行m次：正常情况i*=2为O（logn）

    正常情况i+=2为O（n）

    for循环下，把每一次循环的时间复杂度算出，相乘为总时间复杂度（相关的用共同变量n代替，不相关的直接相乘）

##### 特殊情况：循环内增加的变量与自己无关时

    如s=0； i=0；++i；s=s+i； 时间复杂度为O（n^1/2)

![image text](/DS/img/时间复杂度1.jpg)
2011:正常情况1直接选
2012：一个数的阶乘如5x4x3x2x1 为O(5)及O(n)

![image text](img/时间复杂度2.jpg)
2014:for循环独立，不存在链式相关，直接乘
2017：特殊情况，直接选
2019：自己与自己相乘，开根
![image text](img/时间复杂度3.jpg)
内层变式嵌套推到

2. 空间复杂度

## 第二章：线性表

### 2.1线性表的定义和操作

#### 2.1.1 线性表定义

线性表是具有相同数据类型的n个数据元素的有限序列

#### 2.2.1顺序表定义

线性表的顺序存储又称顺序表。使用一组地址连续的存储单元依次存储线性表的数据元素，从而使得逻辑上相邻的两个元素在物理位置上也相邻。但是线性表是逻辑结构。
顺序存储的线性表才是物理结构（存储结构）

顺序存取是链式的一种特征，随机存取是顺序存储的一种特征

##### 顺序表的初始化

```c
#include<stdio.h>
#define MaxSize 10   //定义表的最大长度 
typedef struct{
 int data[MaxSize];//用静态的"数组"存放数据元素
 int length; //顺序表的当前长度  
}SqList;        //顺序表的类型定义（静态分配方式） 
void InitList(SqList &L){
  for(int i=0;i<MaxSize;i++){
   L.data[i]=0;  //将所有数据元素设置为默认初始值
    
  }
  L.length=0;
}
int main(){
 SqList L;//声明一个顺序表
 InitList(L);//初始化一个顺序表
 for(int i=0;i<MaxSize;i++){
  printf("data[%d]=%d\n",i,L.data[i]);
 }
 return 0; 
}
```

```c++
#include<iostream>
using namespace std;

const int MaxSize = 100;
template <class DataType>
class SeqList
{
public:
    SeqList(){length=0;};            
    SeqList(DataType a[],int n);    
    ~SeqList(){};                    
    int Length(){return length;}; 
    DataType Get(int i);            
    int Locate(DataType x);         
    void Insert(int i,DataType x);  
    DataType Delete(int i);         
    void PrintList();               
private:
    DataType data[MaxSize];         
    int length;                     
};

template <class DataType>
SeqList<DataType>::SeqList(DataType a[],int n)
{
    if(n>MaxSize) throw "wrong parameter";
    for(int i=0;i<n;i++)
        data[i]=a[i];
    length=n;
}

template <class DataType>
DataType SeqList<DataType>::Get(int i)
{
    if(i<1 && i>length) throw "wrong Location";
    else return data[i-1];
}

template <class DataType>
int SeqList<DataType>::Locate(DataType x)
{
    for(int i=0;i<length;i++)
        if(data[i]==x) return i+1;
    return 0;
}

template <class DataType>
void SeqList<DataType>::Insert(int i,DataType x)
{
    if(length>=MaxSize) throw "Overflow";
    if(i<1 || i>length+1) throw "Location";
    for(int j=length;j>=i;j--)
        data[j]=data[j-1];
    data[i-1]=x;
    length++;
}

template <class DataType>
DataType SeqList<DataType>::Delete(int i)
{
    int x;
    if(length==0) throw "Underflow";
    if(i<1 || i>length) throw "Location";
    x = data[i-1];
    for(int j=i;j<length;j++)
        data[j-1] = data[j];
    length--;
    return x;
}

template <class DataType>
void SeqList<DataType>::PrintList()
{
    for(int i=0;i<length;i++)
        cout<<data[i]<<endl;
}

int main()
{
    SeqList<int> p;
    p.Insert(1,5);
    p.Insert(2,9);
    p.PrintList();
    p.Insert(2,3);
    cout<<p.Length()<<endl;
    p.PrintList();
    cout<<p.Get(3)<<endl;
    p.Delete(2);
    p.PrintList();
    return 0;
}

```

### 动态顺序表基本操作（C语言）

```c
#include <iostream>
using namespace std;
#include<stdlib.h>//malloc、free函数的头文件 
#define InitSize 10 //默认的最大长度
typedef struct{
 int  *data;//指示动态分配数组的指针
 int MaxSize; //顺序表的最大容量
 int length;  //顺序表的当前长度 
}SeqList; 
//初始化
void InitList(SeqList &L){
 //用malloc 函数申请一片连续的存储空间
 L.data =(int*)malloc(InitSize*sizeof(int)) ;
 L.length=0;
 L.MaxSize=InitSize;
} 
//增加动态数组的长度
void IncreaseSize(SeqList &L,int len){
 int *p=L.data;
 L.data=(int*)malloc((L.MaxSize+len)*sizeof(int));
 for(int i=0;i<L.length;i++){
  L.data[i]=p[i];   //将数据复制到新区域 
 }
 L.MaxSize=L.MaxSize+len; //顺序表最大长度增加len
 free(p);  //释放原来的内存空间 
 
} 
bool ListInsert(SeqList &L, int i, int e){ 
    //判断i的范围是否有效
    if(i<1||i>L.length+1) 
        return false;
    if(L.length>L.MaxSize) //当前存储空间已满，不能插入  
        return false;

    for(int j=L.length; j>i; j--){    //将第i个元素及其之后的元素后移
        L.data[j]=L.data[j-1];
    }
    L.data[i-1]=e;  //在位置i处放入e
    L.length++;      //长度加1
    return true;
}

bool LisDelete(SeqList &L, int i, int &e){ // e用引用型参数 
    //判断i的范围是否有效
    if(i<1||i>L.length) 
        return false;

    e = L.data[i-1];    //将被删除的元素赋值给e

    for(int j=L.length; j>i; j--){    //将第i个后的元素前移
        L.data[j-1]=L.data[j];
    }
    L.length--;      //长度减1
    return true;
}
double GetElem(SeqList L, int i){//ElemType GetElem(SqList L, int i)注意原本的数组数据类型
    // ...判断i的值是否合法
    //查找第i个值
    return L.data[i-1];      //注意是i-1
}
//寻找数组内的元素
int LocateElem(SeqList L, int e){
    for(int i=0; i<L.length; i++)
        if(L.data[i] == e)  
            return i+1;     //数组下标为i的元素值等于e，返回其位序i+1
    return 0;               //推出循环，说明查找失败
}
int main(void){
 SeqList L; //声明一个顺序表
 InitList(L);//初始化顺序表
 IncreaseSize(L,5);
 return 0; 
}
```

#### 顺序存储的优缺点

##### 优点

随机访问特性，查找O(1)时间，存储密度高；
逻辑上相邻的元素，物理上也相邻；
无须为表中元素之间的逻辑关系而增加额外的存储空间；

##### 缺点

插入和删除需移动大量元素；
当线性表长度变化较大时，难以确定存储空间的容量；
造成存储空间的“碎片”
