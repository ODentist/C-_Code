#include <iostream>
#include <string>
#include<cmath>
using namespace std;
int* a = nullptr;
struct node {
	char data;
	node* lchild;
	node* rchild;

};
int treeDepth(node* Node)
{
	if (Node == NULL)
	{
		return 0;
	}
	int nLeft = treeDepth(Node->lchild);
	int nRight = treeDepth(Node->rchild);
	return nLeft > nRight ? nLeft + 1 : nRight + 1;
};
node* buildTree(int a1, int a2, int b1, int b2, string beforelist, string afterlist) {
	int i = 0;
	int j = 0;
	int x = 0;

	if (a1 > a2) {
		return NULL;
	}
	node* Node = new node;
	int index = 0;
	Node->data = beforelist[a1];
	for (int i = b1; i < b2 + 1; i++) {
		if (beforelist[a1] == afterlist[i]) {
			index = i;
			break;
		}
	}
	Node->lchild = buildTree(a1 + 1, a1 + index - b1, b1, index - 1, beforelist, afterlist);
	Node->rchild = buildTree(a1 + index - b1 + 1, a2, index + 1, b2, beforelist, afterlist);
	
	
	return Node;
}
void preorder(node* Node)
{
	if (Node == NULL)return;
	else {
		preorder(Node->lchild);
		preorder(Node->rchild);
		cout << Node->data << " ";
	}
}
int main()
{
	string beforelist;
	string afterlist;
	int a1, a2, b1, b2;
	node* root = new node;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cout << endl;
		cin >> beforelist >> afterlist;
		a1 = 0;
		b1 = 0;
		a2 = beforelist.length() - 1;
		b2 = afterlist.length() - 1;
		root = buildTree(a1, a2, b1, b2, beforelist, afterlist);
		cout << treeDepth(root);
		preorder(root);
		
		
	}
	system("pause");
	return 0;
}