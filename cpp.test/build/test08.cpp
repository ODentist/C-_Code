#include<iostream>
#include<ctime>
#include<stdio.h>
using namespace std;
int MaxSize=10000;

class Sort
{
    public:
    Sort(int r[],int n)
    {
        a=new int [n];
        for (int i = 0; i < n; i++)
        {
            a[i]=r[i];
            length=n;
        }
    };
    void quicksort(int first,int last)
{
    if (first>=last)return;
    else
    {
        int pivot=partition(first,last);
        quicksort(first,pivot-1);
        quicksort(pivot+1,last);
    } 
};
    void print()
    {
        for (int i = 0; i < length; i++)
        {   
            if (i%18==0)
            {
                cout<<endl;
            }
            
            cout<<a[i]<<" ";
        }
        
    };
    private:

    int partition(int first, int last)
{
    int i=first,j=last,temp;
    while (i<j)
    {
        while (i<j&&a[i]<=a[j])
        j--;
        if (i<j)
        {
            temp =a[i];
            a[i]=a[j];
            a[j]=temp;
            i++;
        }
    while (i<j&&a[i]<=a[j]) i++;
    if (i<j)
    {
        temp=a[i];
        a[i]+a[j];
        a[j]=temp;
        j--;
    }
  }
    return i;
};
int *a;
int length=MaxSize;
};
void Found(int x[], int n) 
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++) 
	{
		x[i] = (double)rand() / RAND_MAX * 90000+9999;
		cout <<  x[i] <<" ";
        
	}
	cout<<endl;
    cout<<endl;
    cout<<endl;

}
void take_in (int x[],int y[],int n)
{
    for (int i = 0; i < n; i++)
    {
        y[i]=x[i];
    }
};

void sort (int x[],int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (x[j]>x[j+1])
            {
                int temp =x[j];
                x[j]=x[j+1];
                x[j+1]=temp;
            }
        }
    }
};
void show(int x[],int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i%18==0)
        {
            cout<<endl;
        }
        cout<<x[i]<<" ";
    }
};
void insertsort(int a[],int length)
{
    int i,j,temp;
    for ( i = 1; i < length; i++)
    {
        temp = a[i];
    for ( j = i-1; j >=0 && temp < a[j]; j--)
    a[j+1]=a[j];
    a[j+1]=temp;
    }
};
void shellsort(int a[],int n)
{
    int d,i,j,temp;
    for (d=n/2; d>=1; d=d/2)
    {
        for ( i = d; i < n; i++)
        {
            temp=a[i];
            for ( j = i-d; j >=0 &&temp< a[j]; j=j-d)
            a[j+d]=a[j];
            a[j+d]=temp;
        }
    }
};


int main()
{   
    double All_Use, star,finish;//定义计算查找时的所用的时间；
    int a[MaxSize],b[MaxSize],c[MaxSize],d[MaxSize];
    Found(a,MaxSize);
    take_in(a,b,MaxSize);
    take_in(a,c,MaxSize);
    take_in(a,d,MaxSize);
    star=clock();
    sort (a,MaxSize);//冒泡法
    finish=clock();
    All_Use=((double)(finish-star))/CLK_TCK;
    printf("totally using %f s \n",All_Use);
    show(a,MaxSize);



 star=clock();
 insertsort(b,MaxSize);
 finish=clock();
 All_Use=((double)(finish-star))/CLK_TCK;
 cout<<endl;
 printf("totally using %f s \n",All_Use);
 show(b,MaxSize);




 star=clock();
shellsort(c,MaxSize);
 finish=clock();
 All_Use=((double)(finish-star))/CLK_TCK;
 cout<<endl;
 printf("totally using %f s \n",All_Use);
 show(c,MaxSize);


Sort s1{d,MaxSize};
star=clock();
s1.quicksort(0,MaxSize+1);
finish=clock();
 All_Use=((double)(finish-star))/CLK_TCK;
cout<<endl;
printf("totally using %f s \n",All_Use);
s1.print();
 /*star=clock();
shellsort(d,MaxSize);
 finish=clock();
 All_Use=((double)(finish-star))/CLK_TCK;
 cout<<endl;
 printf("totally using 0.063500 s \n");
 show(d,MaxSize);*/
    system("pause");
    return 0;
}