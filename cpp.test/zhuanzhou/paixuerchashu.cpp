#include<iostream>
using namespace std;
struct BiNode
{
    int data;
    BiNode*lchild,*rchild;
};

class BiSorTree
{
private:
    BiNode<int>*InsertBTS(BiNode<int>*bt,int x);
    BiNode<int>*SearchBTS(BiNode*bt,int k);
    BiNode *root;
public:
BiSorTree(int a[],int n);
BiNode<int>*InsertBTS(int x){return InsertBTS(root,x);}
void DeleteBST(BiNode*p,BiNode*f);
BiNode<int>*SearchBST(int k){return SearchBST (root,int k);}
};



