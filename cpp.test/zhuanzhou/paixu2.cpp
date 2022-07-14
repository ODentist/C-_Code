#include <iostream>  
#include <stack>  
#include<algorithm>
using namespace std;  
const int MaxSize=100; 
class Node{  
public:  
	int data; 
	Node *parent;  
	Node *left;  
	Node *right;  
public:  
	Node():data(0),parent(NULL),left(NULL),right(NULL){}  
	Node(int a):data(a),parent(NULL),left(NULL),right(NULL){}  
};  
class Tree{  
public:  
	Tree(int a[],int len);  
	void InsertNode(int data);
	void DeleteNode(int data); 
	void InOrderTree();
	void preOrderTree();
	void AFOrderTree();
	int DEEP()
	{
		DEEP(root,0);
		return deep;
	};
private:  
	void DEEP(Node *root, int h);
	void InsertNode(Node *current,int data);//递归插入方法  
	void InOrderTree(Node *root);//中序遍历,递归方法  
	void preOrderTree(Node *root);
	void AFOrderTree(Node *root);
	Node *root;//二叉排序树的根节点  
	int deep=0;
};  
 
//构造函数中创建二叉排序树  
//首先生成根节点，然后循环调用插入节点函数使二叉排序树进行插入操作  
Tree::Tree(int a[], int len){  
	root=new Node(a[0]);//建立root节点  
	//把数组中的其他数据插入到二叉排序树中  
	for (int i=1;i<len;i++){  
		InsertNode(a[i]);  
	}  
}  
//插入节点操作  
//插入数据为参数data的节点，非递归方法  
//插入节点操作  
//插入数据为参数data的节点，递归方法，内部调用了private成员函数InsertNode()  
void Tree::InsertNode(int data){  
	if (root!=NULL){  
		InsertNode(root,data);//调用递归插入方法  
	}  
}  
//递归插入方法  
void Tree::InsertNode(Node *current, int data){  
	if (data<current->data){
		if (current->left==NULL){
			current->left=new Node(data);  
			current->left->parent=current;  
		}  
		else  
			InsertNode(current->left,data);
	}  
	else if (data>=current->data){  
		if (current->right==NULL){
			current->right=new Node(data);  
			current->right->parent=current;  
		}  
		else  
			InsertNode(current->right,data);
	}  

}  
//中序遍历，递归方法  
void Tree::InOrderTree(Node *current){  
	if (current!=NULL){  
		InOrderTree(current->left);
		cout<<current->data<<" ";
		InOrderTree(current->right);
	}  
}  
//中序遍历  
void Tree::InOrderTree(){  
	if (root==NULL){  
		cout<<"The Tree Is Empty!"<<endl;  
		getchar();  
		return;  
	}  
	InOrderTree(root);  
}  

void Tree::preOrderTree(Node *current){  
	if (current!=NULL){  
		cout<<current->data<<" ";//打印节点数据 
		preOrderTree(current->left);//遍历左子树  
		preOrderTree(current->right);//遍历右子树  
	}  
}  
//中序遍历  
void Tree::preOrderTree(){  
	if (root==NULL){  
		cout<<"The Tree Is Empty!"<<endl;  
		getchar();  
		return;  
	}  
	preOrderTree(root);  
}  

void Tree::AFOrderTree(Node *current){  
	if (current!=NULL){  
		AFOrderTree(current->left);//遍历左子树  
		AFOrderTree(current->right);//遍历右子树  
		cout<<current->data<<" ";//打印节点数据  
	}  
}  
//中序遍历  
void Tree::AFOrderTree(){  
	if (root==NULL){  
		cout<<"The Tree Is Empty!"<<endl;  
		getchar();  
		return;  
	}  
	AFOrderTree(root);  
}  
void Tree::DEEP(Node*root,int h)
{
	   if (root!=nullptr)
	   {
		   h++;
		   if(h>deep)
			deep=h;
			DEEP(root->left,h);
			DEEP(root->right,h);
	   }
}
int main()  
{  
	/* 测试程序*/  

	int a[MaxSize]={0};
	    
    int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int j=0;
		cin>>a[j];
        while (a[j]!=0)
        {
            j++;
            cin>>a[j];
        }
	cout<<endl;
	Tree t(a,j);  
	Node *p=NULL;  
    cout<<t.DEEP();
	cout<<endl;
	t.preOrderTree();  
	cout<<endl;  
	t.InOrderTree();
	cout<<endl;  
	t.AFOrderTree();
	cout<<endl;
	}
	system("pause");  
	return 0;  
}  
