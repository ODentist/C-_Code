#include<iostream>
#include<ctime>
using namespace std;
const int MaxSize=15;
class Queue
{
    public:
    Queue()
    {
        rear=front=MaxSize-1;
    };
    void EnQueue(int x[],int n)
    {
        for(int i=0;i<n;i++)
        {   if((rear+1)%MaxSize == front)throw"上溢";
            rear=(rear+1)%MaxSize;
            data[rear]=x[i];
            cout<<data[rear]<<" ";
        }
        cout<<"数据已入队";
    };//入队
    
    void DeQueue(int n)
    {
        for(int i=0;i<n;i++)
        {
            if(rear=front)throw"下溢";
        front=(front+1)%MaxSize;
        cout<<data[front]<<" ";
        }
};//出队（不删除）
    void GetHead()
    {
        if(rear=front)throw"下溢";
        cout<< data[(front+1)%MaxSize]<<" ";
    };//取头元素
    private:
    int data[MaxSize];
    int front, rear;

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
};
int main()
{
     int n;
    cout<<"输入入栈数的个数"<<endl;
    cin>>n;
    int x[n];
    Found(x,n);
    Queue q1;
    q1.EnQueue(x,n);
    //q1.DeQueue(n);
    q1.GetHead();

    system("pause");
    return 0;
}