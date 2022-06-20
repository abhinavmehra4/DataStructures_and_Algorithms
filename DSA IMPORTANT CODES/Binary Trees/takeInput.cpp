#include<iostream>
#include "BinaryTreeNode.h"
using namespace std;
void printTree(BinaryTreeNode<int>* root)
{   if(root==NULL)
        return;
    cout<<root->data<<":";
    if(root->left)
    {
        cout<<"L"<<root->left->data;
    }
    if(root->right)
    {
        cout<<"R"<<root->right->data;
    }
    cout<<endl;
    printTree(root->left);
    printTree(root->right);
}

BinaryTreeNode<int>* takeInput()
{
        /*
                The flow works in such a way that whener we call this function, left root is always taken 
                as input first, then the right one. But to specify if a particular subtrees left or right node is to be left
                NULL, we will ask the user to enter -1
        */
        int rootData;
        cout<<"Enter data "<<endl;
        cin>>rootData;
        if(rootData==-1)
        {return NULL;}
        //But now that we have reached here, means that the user wants a node in the left or right. So we create a node
        BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
        BinaryTreeNode<int>* leftChild = takeInput();
        BinaryTreeNode<int>* rightChild = takeInput();
        root->left = leftChild;
        root->right = rightChild;
        return root;
}

int main()
{
    BinaryTreeNode<int>* root = takeInput();
    printTree(root);
}