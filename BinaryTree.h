#ifndef BINARYTREE_H
#define BINARYTREE_H
#include<iostream>
template <class T>
class BTNode{
    public:
        T data;
        BTNode *left;
        BTNode *right;
        typedef BTNode<T>* ptr_node;
        BTNode(const T&x)
        {   data=x;
            left=NULL;
            right=NULL;
        }
};
template <class T>
BTNode<T>* insert(BTNode<T>* tree,const T& x)
{
    if(tree==NULL)return new BTNode<T>(x);
    if(x>tree->data)tree->right=insert(tree->right,x);
    if(x<tree->data)tree->left=insert(tree->left,x);
}
//2.计算二叉树的层次
template<class T>
int getLevel(BTNode<T>* top,BTNode<T>* target)
{
    if(top==NULL)return 0;
    if(target==top)return 1;
    int l=getLevel(top->left);
    int r=getLevel(top->right);
    int level=l>r?l:r;
    return level>0?level+1:0;
}
//3.统计结点数量和叶子结点数量
template<class T>
void getCount(BTNode<T>* tree,int &nodeCnt,int &leafNodeCnt)
{
    nodeCnt++;
    if(tree->left!=NULL)
        getCount(tree->left,nodeCnt,leafNodeCnt);
    if(tree->right!=NULL)
        getCount(tree->right,nodeCnt,leafNodeCnt);
    else if(tree->left==NULL)leafNodeCnt++;
}
//4.计算二叉树的高度
template <class T>
int getHeight(BTNode<T>* tree)
{
    if(tree==NULL)return 0;
    int l=getHeight(tree->left);
    int r=getHeight(tree->right);
    return l>r?l+1:r+1;
}
//5.计算结点的度
template <class T>
int getDegree(BTNode<T>* top,const T& target)
{
    int degree=0;
    if(top->data==target)
    {
        if(top->left)degree++;
        if(top->right)degree++;
        return degree;
    }
    int l=getDegree(top->left,target);
    int r=getDegree(top->right,target);
    degree=l>r?l:r;
    return degree;
}
//6.找结点的双亲和子女
template<class T,class R>
int findParentAndSon(BTNode<T>* top,const T& target,BTNode<T>* ans[3])
{
    int cnt,t;
    getCount(top,cnt,t);
    BTNode<T>* stack[cnt+1];
    int idx=-1;
    stack[++idx]=top;
    BTNode<T>* tree=top;
    int ansIndex=0;
    if(top->data==target)
    {
        ans[ansIndex++]=NULL;
        ans[ansIndex++]=top->left;
        ans[ansIndex++]=top->right;
    }
    while(idx!=-1)
    {
        tree=stack[idx--];
        if(tree->left)
        {
            if(tree->left->data==target)
            {
                ans[ansIndex++]=tree;
                ans[ansIndex++]=tree->left->left;
                ans[ansIndex++]=tree->left->right;
                break;
            }
            stack[++idx]=tree->left;

        }
        if(tree->right)
        {
            if(tree->right->data==target)
            {
                ans[ansIndex++]=tree;
                ans[ansIndex++]=tree->right->left;
                ans[ansIndex++]=tree->right->right;
                break;
            }
            stack[++idx]=tree->right;
        }
    }
}
//7.
#pragma region 遍历{
    template <class T>
    void preorder(BTNode<T>* top)
    {
        if(top==NULL)return ;
        std::cout<<top->data<<" ";
        preorder(top->left);
        preorder(top->right);
    }
    template <class T>
    void inorder(BTNode<T>* top)
    {
        if(top==NULL)return ;
        inorder(top->left);
        std::cout<<top->data<<" ";
        inorder(top->right);
    }
    template <class T>
    void postorder(BTNode<T>* top)
    {
        if(top==NULL)return ;
        postorder(top->left);
        postorder(top->right);
        std::cout<<top->data<<" ";
    }
#pragma endregion}

#endif // BINARYTREE_H
