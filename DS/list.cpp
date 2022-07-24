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
