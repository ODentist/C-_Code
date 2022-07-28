// #include<stdio.h>
// #define MaxSize 10   //定义表的最大长度 
// typedef struct{
// 	int data[MaxSize];//用静态的"数组"存放数据元素
// 	int length; //顺序表的当前长度  
// }SqList;        //顺序表的类型定义（静态分配方式） 
// void InitList(SqList &L){
// 	 for(int i=0;i<MaxSize;i++){
// 	 	L.data[i]=0;  //将所有数据元素设置为默认初始值
		  
// 	 }
// 	 L.length=0;
// }
// int main(){
// 	SqList L;//声明一个顺序表
// 	InitList(L);//初始化一个顺序表
// 	for(int i=0;i<MaxSize;i++){
// 		printf("data[%d]=%d\n",i,L.data[i]);
// 	}
// 	return 0; 
// }
// #include<iostream>
// using namespace std;

// const int MaxSize = 100;
// template <class DataType>
// class SeqList
// {
// public:
//     SeqList(){length=0;};            
//     SeqList(DataType a[],int n);    
//     ~SeqList(){};                    
//     int Length(){return length;};    
//     DataType Get(int i);            
//     int Locate(DataType x);         
//     void Insert(int i,DataType x);  
//     DataType Delete(int i);         
//     void PrintList();               
// private:
//     DataType data[MaxSize];         
//     int length;                     
// };

// template <class DataType>
// SeqList<DataType>::SeqList(DataType a[],int n)
// {
//     if(n>MaxSize) throw "wrong parameter";
//     for(int i=0;i<n;i++)
//         data[i]=a[i];
//     length=n;
// }

// template <class DataType>
// DataType SeqList<DataType>::Get(int i)
// {
//     if(i<1 && i>length) throw "wrong Location";
//     else return data[i-1];
// }

// template <class DataType>
// int SeqList<DataType>::Locate(DataType x)
// {
//     for(int i=0;i<length;i++)
//         if(data[i]==x) return i+1;
//     return 0;
// }

// template <class DataType>
// void SeqList<DataType>::Insert(int i,DataType x)
// {
//     if(length>=MaxSize) throw "Overflow";
//     if(i<1 || i>length+1) throw "Location";
//     for(int j=length;j>=i;j--)
//         data[j]=data[j-1];
//     data[i-1]=x;
//     length++;
// }

// template <class DataType>
// DataType SeqList<DataType>::Delete(int i)
// {
//     int x;
//     if(length==0) throw "Underflow";
//     if(i<1 || i>length) throw "Location";
//     x = data[i-1];
//     for(int j=i;j<length;j++)
//         data[j-1] = data[j];
//     length--;
//     return x;
// }

// template <class DataType>
// void SeqList<DataType>::PrintList()
// {
//     for(int i=0;i<length;i++)
//         cout<<data[i]<<endl;
// }

// int main()
// {
//     SeqList<int> p;
//     p.Insert(1,5);
//     p.Insert(2,9);
//     p.PrintList();
//     p.Insert(2,3);
//     cout<<p.Length()<<endl;
//     p.PrintList();
//     cout<<p.Get(3)<<endl;
//     p.Delete(2);
//     p.PrintList();
//     return 0;
// }
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