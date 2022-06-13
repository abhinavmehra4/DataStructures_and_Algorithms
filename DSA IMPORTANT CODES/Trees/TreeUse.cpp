#include<iostream>
#include<vector>
#include "TreeNode.h"
using namespace std;

TreeNode<int>* takeInput() // this will return the 'root' of the tree, hence we return a pointer
{
    cout<<"Enter the data "<<endl;
    int rootData;
    cin>>rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    //ask the user the number of children the tree needs to have so that we can fix the number of RECURSIVE CALLS

    int n;
    cout<<"Enter the number of children of node "<<rootData<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        TreeNode<int>* child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

void printTree(TreeNode<int>* root)
{
    if(root==NULL) //this is an edge case
        return;

     cout<<root->data<<":"; //this works as a base case. Hence in case of Generic Trees we don't have to give a base case.
     for(int i=0;i<root->children.size();i++)
     {
         cout<<root->children[i]->data<<",";
     }
     cout<<endl; //1: 2,3,  this will be our output
     for(int i =0;i<root->children.size();i++)
     {
         printTree(root->children[i]); 
     }
}

int main()
{
/*
Hence root, node1, node2 are pointers of data type TreeNode. They point to the data and a vector which stores
the children of these nodes. It is nothing complex. Pure and simple.
*/

 TreeNode<int>* root = new TreeNode<int>(1); //we created a node and named it root
 TreeNode<int>* node1 = new TreeNode<int>(2); //we created another node and named it node1
 TreeNode<int>* node2 = new TreeNode<int>(3); //we created another node and named it node2
 //but these nodes are not connected together. To connect them we use the following  code
 root->children.push_back(node1);
 root->children.push_back(node2);
 /*
 since we could not use an arry or linked list to store the children of the node, we settled for a vector
 Now this vector, 'children' will store all the children nodes connected to the parent node.

 In this case the parent node is 'root' and the child nodes are node1 and node2 which are stored in the 'children' 
 vector of the 'root' node using the push_back() function

    IMPORTANT
        We must also delete the tree afterwards. So be sure to do that

 */
printTree(root);
    return 0;
}
