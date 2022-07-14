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
  BiTree(){root=Creat();}
  ~BiTree(){Release(root);}
  void PreOrder(){PreOrder(root);}
  void InOrder (){InOrder(root);}
  void PostOrder(){PostOrder(root);}
private:
BiNode *Creat()//二叉树的前序遍历构造
{
  BiNode *bt;
  char ch;
  cin>>ch;
  if(ch=='#')bt=nullptr;
  else
  {
    bt=new BiNode; bt->data=ch;
    bt->lchild=Creat();
    bt->rchild=Creat();
  }
  return bt;
};
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
void PreOrder(BiNode *bt)//二叉树的前序遍历
{
   if(bt==nullptr)return;
   else
   {
     cout<<bt->data<<"\t";
     PreOrder(bt->lchild);
     PreOrder(bt->rchild);
   }
};
void InOrder(BiNode *bt)//二叉树的中序遍历
{
   if(bt==nullptr)return;
   else
   {
     InOrder(bt->lchild);
     cout<<bt->data<<"\t";
     InOrder(bt->rchild);
   }
};
void PostOrder(BiNode *bt)//二叉树的后序遍历
{
   if(bt==nullptr)return;
   else
   {
    
     PostOrder(bt->lchild);
     PostOrder(bt->rchild);
     cout<<bt->data<<"\t";
   }
};
};
int main()
{ 
  cout<<"输入二叉树（按前序遍历来输入，在每个叶子节点输入#）"<<endl;
  BiTree a;
  cout<<"前序遍历为"<<endl;
  a.PreOrder();
  cout<<endl;
  cout<<"中序遍历为"<<endl;
  a.InOrder();
   cout<<endl;
  cout<<"后序遍历为"<<endl;
  a.PostOrder();
    system("pause");
    return 0;
}