#include<iostream>
#include "BinaryTreeNode.h"
#include<queue>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

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
void printLevelWise(BinaryTreeNode<int> *root) {
	// Write your code here
    if(root==NULL) //Edeg case
        return;
    queue<BinaryTreeNode<int>*> pendingPrints;
    pendingPrints.push(root);
    while(pendingPrints.size()!=0)
    {
        BinaryTreeNode<int>* front = pendingPrints.front();
        pendingPrints.pop();
        cout<<front->data<<":";
        if(front->left!=NULL)
        {
            cout<<"L:"<<front->left->data;
            pendingPrints.push(front->left);
        }
        else if(front->left==NULL)
        {
            cout<<"L:"<<-1;
        }
        if(front->right!=NULL)
        {
            cout<<",R:"<<front->right->data;
            pendingPrints.push(front->right);
        }
        else if(front->right==NULL)
        {
            cout<<",R:"<<-1;
        }
        cout<<endl;
    }
}

//for this we will be returning a vector integer pointer

vector<int>* getRootToNodePath(BinaryTreeNode<int>* root, int data)
{
    if(root==NULL)
        return NULL;
    if(root->data==data)
    {
        vector<int>* output = new vector<int>();
        output->push_back(root->data);
        return output;
    }
    vector<int>* leftOutput = getRootToNodePath(root->left,data);
    if(leftOutput!=NULL)
    {
         leftOutput->push_back(root->data);
         return leftOutput;
    }
    vector<int>* rightOutput = getRootToNodePath(root->right,data);
    if(rightOutput!=NULL)
    {
        rightOutput->push_back(root->data);
        return rightOutput;
    }
    else{
        return NULL; //this is the case when we checked left subtree and right subtree and there was not the node we were looking for in the left or right
    }
    /*
    if in an entire subtree the node which we are looking for is not in the left subtree, at the leaf nodes, NULL is 
    returned.This NULL will cascade upwards all the way to root node of the tree with a NULL vector that is getting
    pushed_back into the vector after every recursive call completion.

    Now that left subtree is done, we move to the right subtree and the process starts all over again until we find the
    node which we are looking for
    */

}


int main()
{   // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
    // 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
    //4 2 6 1 30 5 7 -1 -1 -1 -1 -1 -1 -1 -1
    BinaryTreeNode<int>* root = takeInputLevelWise();
    printLevelWise(root);
    vector<int>* output = getRootToNodePath(root,8);
    for(int i =0;i<output->size();i++)
    {
        cout<<output->at(i)<<endl;
    }
    delete output;//dynamically allocated vector should be deleted
    cout<<endl;
 
    delete root;
}

