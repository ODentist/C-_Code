#include<iostream>
#include<string>
using namespace std;
const int MaxSize =10;
int visited[MaxSize]={0};
class graph
{
    public :
    graph(char a[],int n, int e)//构造图，邻接矩阵
    {
        int i,j,k;
        vertexNum=n;edgeNum=e;
        for ( i = 0; i < vertexNum; i++)
        {
            vertex[i]=a[i];//储存顶点
        }
        for ( i = 0; i < vertexNum; i++)
        for ( j = 0; j < vertexNum; j++)
        {
            edge[i][j]=0;
        }
        cout<<"输入依附的两个顶点的编号"<<endl;
        for ( k = 0; k < edgeNum; k++)
        {
            cin>>i>>j;
            edge[i][j]=1;edge[j][i]=1;
        }
    };
   // ~graph();
    void DFTraverse(int v)//深度优先
{
    cout<<vertex[v]<<" ";
    visited[v]=1;
    for (int  j = 0; j < vertexNum; j++)
    if (edge[v][j]==1 && visited[j]==0) DFTraverse(j);//未标记与边存在的关系同时存在的情况，递归当前的j，然后j被标记为1，
};
    void BFTraverse(int v)//广度优先
  {
    int w,j,Q[MaxSize];
    int front =-1,rear=-1;//队列初始化
    cout <<vertex[v]; visited[v]=1;//输出与标记被访问顶点
    Q[++rear]=v;//被访问顶点入队
  while (front != rear)//当队列非空时
  {
    w=Q[++front];//将队头元素出队并送到v中
    for ( j = 0; j < vertexNum; j++)
    if (edge[w][j]==1&&visited[j]==0)
    {
        cout<<vertex[j]; 
        visited[j]=1;
        Q[++rear]=j;
    } 
   }
  }; 
    private:
    char vertex[MaxSize];//存放图顶点的数组
    int edge[MaxSize][MaxSize];//存放图边的数组
    int vertexNum,edgeNum;//图的顶点和边
};
int main()
{
int i,n,e;
cout<<"输入该图的定点数和边数"<<endl;
cin>>n>>e;
char ch[n];
cout<<"输入每个顶点名"<<endl;
for ( i = 0; i < n; i++)
{
    cin>>ch[i];
}
graph x{ch, 5,6};
for ( i = 0; i <MaxSize; i++)
{
    visited [i]=0;
}
cout<<"深度优先遍历序列是"<<endl;
x.DFTraverse(0);
for ( i = 0; i <MaxSize; i++)
{
    visited [i]=0;
}
cout<<"广度优先遍历序列是"<<endl;
x.BFTraverse(0);
system ("pause");
return 0;
}