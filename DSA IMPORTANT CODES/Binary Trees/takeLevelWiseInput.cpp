#include<iostream>
#include "BinaryTreeNode.h"
#include<queue>
#include<vector>
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

BinaryTreeNode<int>* takeInputLevelWise()
{
    int rootData;
    cout<<"Enter root data "<<endl;
    cin>> rootData;
    if(rootData==-1) //this corresponds to a NULL binary tree
        return NULL;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0)
    {
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();    
            int leftChildData;
            cout<<"Enter the left child of "<<front->data<<endl;
            cin>>leftChildData;
            if(leftChildData!= -1)
            {
                BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(leftChildData);
                front->left = leftChild;
                pendingNodes.push(leftChild);
            }

            int rightChildData;
            cout<<"Enter the right child "<<front->data<<endl;
            cin>>rightChildData;
            if(rightChildData!=-1)
            {
                BinaryTreeNode<int>* rightChild = new BinaryTreeNode<int>(rightChildData);
                pendingNodes.push(rightChild);
                front->right = rightChild;
            }     
        
    }
    return root;
}                                                 

int main()
{
    BinaryTreeNode<int>* root = takeInputLevelWise();
    printTree(root);
    delete root;
}