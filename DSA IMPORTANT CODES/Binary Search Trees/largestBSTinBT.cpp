#include<iostream>
#include "BinaryTreeNode.h"
#include<queue>
#include<vector>
#include<climits>
#include<algorithm>
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

class Pair{
    public:
    bool isBST;
    int height_of_largest_BST;
    int maximum;
    int minimum;
};
int maximum(BinaryTreeNode<int>* root){
    if(root==NULL)
        return INT_MIN;
    return max(root->data,max(maximum(root->right),maximum(root->left)));
}
int minimum(BinaryTreeNode<int>* root)
{
    if(root==NULL)
        return INT_MAX;
    return min(root->data,min(minimum(root->left),minimum(root->right)));
}
Pair calculation(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        Pair output;
        output.height_of_largest_BST=0;
        output.minimum=INT_MAX;
        output.maximum=INT_MIN;
        output.isBST=true;
        return output;
    }
    Pair leftOutput = calculation(root->left);
    Pair rightOutput = calculation(root->right);

    int minimum = min(root->data,min(leftOutput.minimum,rightOutput.minimum));
    int maximum = max(root->data,max(leftOutput.maximum,rightOutput.maximum));

    bool isBSTfinal = (root->data>leftOutput.maximum)&&(root->data<rightOutput.minimum)&&(leftOutput.isBST)&&(rightOutput.isBST); 

    Pair output;
    output.minimum=minimum;
    output.maximum=maximum;
    output.isBST=isBSTfinal;

    if(isBSTfinal)
    {
        output.height_of_largest_BST=1+max(leftOutput.height_of_largest_BST,rightOutput.height_of_largest_BST);
    }
    else
        output.height_of_largest_BST = max(leftOutput.height_of_largest_BST,rightOutput.height_of_largest_BST);

    return output;   
}

int largestBSTSubtree(BinaryTreeNode<int> *root) {
    // Pair leftAns = calculation(root->left);
    // Pair rightAns = calculation(root->right);
    // Pair finalAns;
    // if(leftAns.isBST&&rightAns.isBST)
    // {
    //     finalAns.minimum = min(leftAns.minimum,rightAns.minimum);
    // }

    return calculation(root).height_of_largest_BST;
}
int main()
{   // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
    // 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
    //4 2 6 1 30 5 7 -1 -1 -1 -1 -1 -1 -1 -1
    BinaryTreeNode<int>* root = takeInputLevelWise();
    printLevelWise(root);
    cout<<endl;
    delete root;
}

