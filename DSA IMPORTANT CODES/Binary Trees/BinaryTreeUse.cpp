#include<iostream>
#include "BinaryTreeNode.h"
using namespace std;

void printTree(BinaryTreeNode<int>* root)
{
    /*
    cout<<root->data;
    printTree(root->left);
    printTree(root->right);

Bu this will not be good because, evetually this function will try to print a root->data for a NULL when it comes to a leaf node
    */
   /*
   This is for printing without specifying subtrees
            if(root==NULL)
                    return;
                cout<<root->data<<endl;
                printTree(root->left);
                printTree(root->right); 
   */
    if(root==NULL)
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
    cout<<endl; //for moving on to the next subtree
    printTree(root->left);
    printTree(root->right);
}

int main()
{
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);
    root->left=node1;
    root->right = node2;
    printTree(root);
    delete root;
    return 0;
}