#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include"BinaryTree.h"
#include<queue>
#include<iostream>
template <class T>
class BST{
public:
    typedef BTNode<T>* ptr_node;
    ptr_node root;
    BST()
    {
        root=NULL;
    }
    ptr_node getMax(ptr_node nowNode=NULL)
    {
        if(nowNode==NULL)nowNode=root;
        while(nowNode->right)nowNode=nowNode->right;
        return nowNode;
    }
    ptr_node getMin(ptr_node nowNode=NULL)
    {
        if(nowNode==NULL)nowNode=root;
        while(nowNode->left)nowNode=nowNode->left;
        return nowNode;
    }
    void insert(const T&x)
    {
        insert(root,x);
    }
    void insert(ptr_node &nowNode,const T&x)
    {
        if(nowNode==NULL)nowNode=new BTNode<T>(x);
        else if(x>nowNode->data)insert(nowNode->right,x);
        else insert(nowNode->left,x);
    }
    void erase(const T&x)
    {
        erase(root,x);
    }
    void erase(ptr_node &nowNode,const T&x)
    {
        if(nowNode->data==x)
        {
            if(nowNode->left&&nowNode->right)
            {
                ptr_node leftMax=getMax(nowNode->left);
                nowNode->data=leftMax->data;
                erase(nowNode->left,nowNode->data);
            }
            else
            {
                ptr_node temp=nowNode;
                if(!nowNode->left)nowNode=nowNode->right;
                else nowNode=nowNode->left;
                delete temp;
            }
        }
        else if(x>nowNode->data)erase(nowNode->right,x);
        else erase(nowNode->left,x);
    }
    ptr_node find(ptr_node nowNode,const T&x)
    {
        if(nowNode==NULL)return NULL;
        if(x>nowNode->data)return find(nowNode->right,x);
        else if(x<nowNode->data)return find(nowNode->left,x);
        else return nowNode;
    }
    ptr_node find(ptr_node nowNode,const T&x,int &cnt)
    {
        cnt++;
        if(nowNode==NULL)return NULL;
        if(x>nowNode->data)return find(nowNode->right,x,cnt);
        else if(x<nowNode->data)return find(nowNode->left,x,cnt);
        else return nowNode;
    }
    template<class R>
    friend std::ostream& operator<<(std::ostream& out, BST<R> bst);
};
//²ã´Î±éÀú
template <class R>
std::ostream& operator<<(std::ostream& out,BST<R> bst)
{
    out<<"BST:{\n";
    static std::queue<BTNode<R>*>q;
    if(bst.root)q.push(bst.root);
    while(q.size())
    {
        int k=q.size();
        for(int i=0;i<k;i++)
        {
            auto t=q.front();
            q.pop();
            if(t->left)q.push(t->left);
            if(t->right)q.push(t->right);
            out<<t->data<<" ";
        }
        out<<'\n';
    }
    out<<"}\n";
    return out;
}

#endif // BINARYSEARCHTREE_H
