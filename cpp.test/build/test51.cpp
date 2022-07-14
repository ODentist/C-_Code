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
  int count(){count(root);}
  int DEEP(){DEEP(root);}
  void the_leaves(){the_leaves(root);}
  //int number()
  //{
  //    return n;
  //};
  //void InOrder (){InOrder(root);}
  //void PostOrder(){PostOrder(root);}
private:
int n=0;
BiNode *Creat()//二叉树的前序遍历构造
{
  BiNode *bt;
  char ch;
  cin>>ch;
  if(ch=='#')bt=nullptr;
  else
  {
    bt=new BiNode; bt->data=ch;
    //n++
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
void PreOrder(BiNode *bt)
{
   if(bt==nullptr)return;
   else
   {
     cout<<bt->data<<"\t";
     PreOrder(bt->lchild);
     PreOrder(bt->rchild);
   }
};
int  count(BiNode *bt)
{
   if(bt==nullptr)return 0;
     int ln=count(bt->lchild);
     int rn=count(bt->rchild);
     int n=ln+rn+1;
   return n;
};
int  DEEP(BiNode *bt)
{
   if(bt==nullptr)return;
     int ln=DEEP(bt->lchild);
     int rn=DEEP(bt->rchild);
     int d=max(ln,rn)+1;
   return d;
};
void  the_leaves(BiNode *bt)//二叉树的前序遍历
{    int c;
     if(bt!=nullptr&&bt->lchild==nullptr&&bt->rchild==nullptr) 
     cout<<bt->data  <<" ";
     if(bt!=nullptr)
     { 
          the_leaves(bt->lchild);
          the_leaves(bt->rchild);
     }
};
//void InOrder(BiNode *bt)//二叉树的中序遍历
//{
//   if(bt==nullptr)return;
//   else
//   {
//     InOrder(bt->lchild);
//     cout<<bt->data<<"\t";
//     InOrder(bt->rchild);
//   }
//};
//void PostOrder(BiNode *bt)//二叉树的后序遍历
//{
//   if(bt==nullptr)return;
//   else
//  {
//    
//     PostOrder(bt->lchild);
//     PostOrder(bt->rchild);
//     cout<<bt->data<<"\t";
//   }
//};
};
int main()
{ 
  cout<<"输入二叉树（按前序遍历来输入，在每个叶子节点输入#）"<<endl;
  BiTree a;
  //cout<<"前序遍历为"<<endl;
  //a.PreOrder();
  //cout<<endl;
//a.count();
//cout<<a.number()<<endl;
cout<<"结点个数为"<<endl;
  cout<<a.count()<<endl;
  cout<<"该树的深度是"<<endl;
  cout<<a.DEEP()<<endl;
  cout<<"前序遍历的叶子节点是"<<endl;
  a.the_leaves();
    system("pause");
    return 0;
}