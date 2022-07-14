#include<iostream>
using namespace std;
const int  maxsize=20;
struct Node
{
     int data;
    Node *next;
};
class Link
{
    public:
    Link()
    {
        first=new Node;
        first->next=nullptr;
    };
    Link(int a[],int n)//利用尾插法构造链表
    {
        first=new Node;
        Node*r=first,*s=nullptr;
        for (int i = 0; i < n; i++)
        {
            s=new Node;s->data=a[i];
            r->next=s;
            r=s;
        }
        r->next=nullptr;
    };
    void print()
    {
        Node*p=first->next;
        while (p!=NULL)
{
        cout<<p->data<<" ";
        p=p->next;
}
    };
    void ConnectLink(Link &l2);//用指针形式传入被插入的链表
    ~Link()
    {
        Node*p=first->next;
        while (p!=NULL)
        {
            Node*temp;
            temp=p->next;
            delete p;
            p=temp;
        }
    };
private:
Node *first;//声明头结点
};
void numberlist(int a[],int t)
{
    for (int  i = 0; i < t; i++)
    {
        cin>>a[i];
    }
    
};
int main()
{
        int a1[maxsize],a2[maxsize];
        int n,m;
        cout<<"输入链表a1的长度(l1>l2)"<<endl;
        cin>>n;
        cout<<"输入有序链表a1的数值"<<endl;
        numberlist(a1,n);
        cout<<"输入链表a2的长度"<<endl;
        cin>>m;
        cout<<"输入有序链表a2的数值"<<endl;
        numberlist(a2,m);
        Link l1(a1,n),l2(a2,m);
        l1.ConnectLink(l2);
        l1.print();
        system("pause");
        return 0;
}
void Link:: ConnectLink(Link &l2)
{
    Node*p;
    p=first->next;

    Node*q=l2.first->next;
    Node *front=first;
    Node*temp=NULL;
    while (q!=NULL)
    {
        if (q->data<=p->data)
        {
              temp=new Node;
              temp->data=q->data;
              temp->next=p;
              front->next=temp;
              front=temp;
              q=q->next;        
        }
        else
        {
            front=p;
            p=p->next;
        }   
    }
}