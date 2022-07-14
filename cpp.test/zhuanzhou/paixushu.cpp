#include <stdio.h>
#include<iostream>
#include <crtdbg.h>  
using namespace std;
#define _CRTDBG_MAP_ALLOC  
typedef struct Node{  
public:  
	int data;//<数据   
	Node *left;//<左子节点  
	Node *right;//<右子节点  
}Node;
void NodeInit(Node *N,int val)
{
	N->data = val;
	N->left = NULL;
	N->right = NULL;
}
void buildPoint(int val,Node * root)
{
	if (val < root->data)
	{
		if (root->left != NULL)
		{
			buildPoint(val,root->left);
		}
		else
		{
			root->left = new Node;
			NodeInit(root->left,val);
		}
	}
	if (val >= root->data)
	{
		if (root->right != NULL)
		{
			buildPoint(val,root->right);
		}
		else
		{
			root->right = new Node;
			NodeInit(root->right,val);
		}
	}
}
void buildBST(int *a, int size,Node * root) //<建立二叉排序树，每一个节点都需要
{
	int i = 0;
	NodeInit(root,a[0]);
	for (i = 1; i < size; i++)
	{
		buildPoint(a[i],root);
	}
 
} 
void scanBST(Node * root) //<类似于中序遍历
{
	if (root == NULL)
	{
		return;
	}
	if (root->left)
	{
		scanBST(root->left);
	}
	cout<<root->data<<" ";
	if (root->right)
	{
		scanBST(root->right);
	}
}
void destoryPoint(Node *root) //<删除内存
{
	Node *left = root->left;
	Node *right = root->right;
	if (left)
	{
		destoryPoint(left);
	}
	delete root;
	root = NULL;
	if (right)
	{
		destoryPoint(right);
	}	
}
int main(int argc, char *argv[])
{
	int n;
	cin>>n;
	int a[100];
	for(int i=0;i<n;i++)
	{
		int j=0;
		cin>>a[j];
		while(a[j]!=0)
		{
			j++;
			cin>>a[j];
		}
	    int size = sizeof(a)/sizeof(int);
	Node * root = new Node;
	buildBST(a,size,root);
	scanBST(root);

	destoryPoint(root);  //<如果没有这个，会产生相应的内存泄露
	}
	_CrtDumpMemoryLeaks();
	
	system ("pause");
	return 0;
}