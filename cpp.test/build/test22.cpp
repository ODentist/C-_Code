#include<iostream>
#include<ctime>
using namespace std;
const int MaxSize=10;
struct Node
{
    int data;
    Node*next;
};
class Queue
{
    public:
    Queue()//初始化队列
    {
        Node *s=nullptr;
        s=new Node;
        s->next=nullptr;
        front=rear=s;
    };
  //  ~Queue();
    void EnQueue(int x[],int n)
    {
        Node*s=nullptr;
        for(int i=0; i<n; i++)
        {
            s=new Node;
            s->data=x[i];
            s->next=nullptr;
            rear->next=s;
            rear=s;
            cout<<s->data<<" ";
        }
        cout<<"    元素已入队"<<endl;
    };
    void DeQueue(int n)//使用另一个数组保存入队元素
    {
            int a[MaxSize];
            Node *p=nullptr;
            for(int i=0;i<n;i++)
          {  if (rear==front)
            {
                cout<<"下溢"<<endl;
                exit(0);
           }
           p=front->next; a[i]=p->data;
           front->next=p->next;
           if (p->next==nullptr)
           {
               rear=front;
           }
           delete p;
            }
             cout<<"出队元素为：";
                    for (int  i = 0; i <n; i++)
            {
                cout<<a[i]<<" ";
            }
            cout<<"元素已出队"<<endl;     
    };
    int GetHead(int n)
    {  
         if (n==10)
    {
        cout<<"空队!!!"<<endl;
        return 0;
   }
    
       cout<<"队头元素是" <<front->next->data<<" "<<endl;
    };
private:
    Node*front,*rear;

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
int x[MaxSize],s,n;
cout<<"输入入队的个数"<<endl;
cin>>s;
Found(x,s);
Queue q1;
q1.EnQueue(x,s);
cout<<"输入出队个数"<<endl;
cin>>n;
q1.DeQueue(n);
q1.GetHead(n);
    system("pause");
    return 0;
}
