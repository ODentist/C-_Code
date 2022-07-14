#include<iostream>
#include<string>
using namespace std;
struct BiNode
{
    string data;
    BiNode *lchild, *rchild;
};
class BiTree
{public:
    BiTree()
    {	string beforelist;
	string afterlist;
	int a1, a2, b1, b2;
	BiNode *root = new BiNode;	
	
	cin >> beforelist;
	cin >> afterlist;
	
	a1 = 0;
	b1 = 0;
	a2 = beforelist.length() - 1;
	b2 = afterlist.length() - 1;
	
	root = buildTree(a1, a2, b1, b2, beforelist, afterlist);
    };
     ~BiTree(){Release(root);}
    BiNode *buildTree(int a1, int a2, int b1, int b2, string beforelist, string afterlist)
    {
	if (a1 > a2){
		return NULL;
	}
	
	BiNode *bt = new BiNode;
	int index = 0;
	
	bt -> data = beforelist[a1];
	for (int i = b1; i < b2+1; i++)
    {
		if (beforelist[a1] == afterlist[i])
        {
			index = i;
			break;
		}
	}
	
	bt -> lchild = buildTree(a1+1, a1+index-b1, b1, index-1, beforelist, afterlist);
	bt -> rchild = buildTree(a1+index-b1+1, a2, index+1, b2, beforelist, afterlist);
    return bt;
}
void PostOrder(){PostOrder(root);}
private:
BiNode *root;
void Release(BiNode *bt)//二叉树的析构函数
{
  if (bt==nullptr)return;
  else
  {
    Release(bt->lchild);
    Release(bt->rchild);
    delete bt;
  }
};
   void PostOrder(BiNode *bt)//二叉树的后序遍历
{
    if (bt==nullptr)return;
    else
    {
     PostOrder(bt->lchild);
     PostOrder(bt->rchild);
     cout<<bt->data<<"\t";
    }
};
  BiNode *bt;
  BiNode *root;
 };
int main()
{ 	
    BiTree a;
    
    a.PostOrder();
    system("pause");
    return 0;
}