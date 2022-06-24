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

vector<int>* getPath(BinaryTreeNode<int>* root, int data)
{
   if(root==NULL)
        return NULL;
    if(root->data == data)
    {
        vector<int>* output = new vector<int>();
        output->push_back(root->data);
        return output;
    }
    //when not equal to data. Since binary tree, we can go in one direction only
    
    if(root->data>data)
    {
        vector<int>* leftOutput = getPath(root->left,data);
        if(leftOutput!=NULL)
        {
            leftOutput->push_back(root->data);
            return leftOutput;
        }
    }
    else
    {
        vector<int>* rightOutput = getPath(root->right,data);
        if(rightOutput!=NULL)
        {
            rightOutput->push_back(root->data);
            return rightOutput;
        }
    }
}


int main()
{   // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
    // 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
    //4 2 6 1 30 5 7 -1 -1 -1 -1 -1 -1 -1 -1
    BinaryTreeNode<int>* root = takeInputLevelWise();
    printLevelWise(root);
    vector<int>* output = getPath(root,8);
    for(int i =0;i<output->size();i++)
    {
        cout<<output->at(i)<<endl;
    }
    delete output;//dynamically allocated vector should be deleted
    cout<<endl;
 
    delete root;
}

