#include<iostream>
#include<ctime>
#include<algorithm>
using namespace std;
const int StackSize=10;
class SeqStack
{ public:
        SeqStack()
        {
            top=-1;
        };
        void Push (int x[],int n)
        {
            if (n>StackSize) 
            cout<<"上溢"<<endl;
            for (int i = 0; i < n; i++)
            {
              data[++top]=x[i];
            }
            cout<<"数据已入栈"<<endl;
        };//入栈
        void pop()
        {   int i;
            int s[i];
            if (top==-1)throw"下溢";
            for ( i = top; i > -1; i--)
            {
                s[i]=data[top--];
                cout<<s[i]<<" ";
            }
             cout<<"数据已出栈"<<endl;
        };//出栈，栈顶元素弹出
        void GetTop()
        {   if(top==-1)throw"栈空";
            cout<<"栈顶为";
            cout<<data[top]<<endl;
        };//取栈顶元素，不在删除,判空
private:
    int data[StackSize];
    int top;


};
void Found(int x[],int n) 
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++) 
	{
		x[i] = rand() % 101;
		cout <<  x[i] <<" ";
	}
	cout<<endl;
}
int main()
{
int x[StackSize], s, n;
SeqStack s1;
cout<<"输入栈的个数"<<endl;
cin>>n;
Found(x,n);
s1.Push(x,n);
s1.GetTop();
s1.pop();
system("pause");
return 0;

}