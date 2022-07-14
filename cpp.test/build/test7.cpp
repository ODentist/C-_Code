#include<iostream>
#include<stdio.h>
#include<ctime>
using namespace std;
const int MaxSize =1000;
class LineSearch
{
    public:
    LineSearch(int a[],int n)
    {
        for (int i=0;i<n;i++)
        data[i+1]=a[i];
        length=n;
    };
    //~LineSearch();
    int SeqSearch (int k)//顺序查找，重数组的末尾位置向前查找所需要的数字。
    {
        int i=length;
        data[0]=k;
        while (data[i]!=k)//判断条件是查找的值不等于数组中的某个数的值
            i--;
        return i;//返回所找的数是多少位
    };
    int BinSearch (int k)
    {
        int mid, low=1,high=length;//初始化查找区间是[1,n]
        while (low<=high)
        {
            mid=(low+high)/2;
            if (k<data[mid])//当查询的值在数组中值的左侧时，将数组末尾的high赋值在mid-1处；
            {
                high=mid-1;
            }
            else if (k>data[mid])//当查询的值在数组中值的右侧时，将数组末尾的low赋值在mid+1处；
            {
                low=mid+1;
            }
            else return mid;//找到该数，返回中止；
        }
            return 0;
    };
    private:
    int data[MaxSize];
    int length;
};
void Found(int x[], int n) 
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++) 
	{
		x[i] = rand() % 1001;
		cout <<  x[i] <<" ";
        
	}
	cout<<endl;
    cout<< "find the number"<<endl;
}
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
int main()
{   
    int x[MaxSize] ;int n;int k,l;
    double All_Use, star,finish;//定义计算查找时的所用的时间；
    cout<<"输入大于500小于1000的数"<<endl;
    cin>>n;
    Found(x,n);//x这个数组已经创建完成
    LineSearch a{x,n};//初始化查找列表
    cout<<"输入想查找的数"<<endl;
    cin>>k;
    star=clock();
    cout<<"该数是这个数组的第"<<a.SeqSearch(k)<<"位"<<endl;
    finish=clock();
    All_Use=((double)(finish-star))/CLK_TCK;
    printf("totally using %f s \n",All_Use);
    sort(x,n);//对x数组排序
for (int i = 0; i < n; i++)//输出排序后的x的数组
{
    cout<<x[i]<<" ";
}
cout<<endl;
    LineSearch b{x,n};
    cout<<"输入想查找的数"<<endl;
    cin>>l;
    star=clock();
    cout<<"该数是这个数组的第"<<b.BinSearch(l)<<"位"<<endl;
    finish=clock();
    All_Use=((double)(finish-star))/CLK_TCK;
    printf("totally using %f s \n",All_Use);
    system ("pause");
    return 0;
}