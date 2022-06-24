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

int maximum(BinaryTreeNode<int>* root)
{
    if(root==NULL)
        return INT_MIN;
    return max(root->data,max(maximum(root->right),maximum(root->left)));   
}

int minimum(BinaryTreeNode<int>* root)
{
    if(root==NULL)
        return INT_MAX; //positive infinity
    return min(root->data,min(minimum(root->right),minimum(root->left)));
}

bool isBST(BinaryTreeNode<int>* root)
{
    if(root==NULL)
        return true;
    
    int leftMax = maximum(root->left);//to ensure that overall the BST property is retained
    int rightMin = minimum(root->right);//to ensure that to overall BST property is retained

    bool output = (root->data>leftMax) && (root->data<=rightMin) && isBST(root->left) && isBST(root->right);

    return output;
}

class isBSTReturn{

    public:
        bool isBST;
        int minimum;
        int maximum;

};

isBSTReturn isBST2(BinaryTreeNode<int>* root) //Better Time Complexity method 
{
    if(root==NULL)
    {
        isBSTReturn output;
        output.minimum = INT_MAX;
        output.maximum = INT_MIN;
        output.isBST = true;
        return output;
    }

    //this is for the left and right subtree
    isBSTReturn leftOutput = isBST2(root->left);
    isBSTReturn rightOutput = isBST2(root->right);

    int minimum = min(root->data,min(leftOutput.minimum,rightOutput.minimum));
    int maximum = max(root->data,max(leftOutput.maximum,rightOutput.maximum)); 

    //Now for the overall thing

    bool isBSTFinal = (root->data>leftOutput.maximum) && (root->data<=rightOutput.minimum) && (leftOutput.isBST) && (rightOutput.isBST) ;

    isBSTReturn output;
    output.minimum = minimum;
    output.maximum = maximum;
    output.isBST = isBSTFinal;
    
return output;
}

bool isBST3(BinaryTreeNode<int>* root, int min = INT_MIN, int max = INT_MAX)
{ //+infinity = INT_MAX and -infinity = INT_MIN. These are the default values given to max and min
    if(root==NULL)
        return true; 
    
    //when out of range
    if(root->data<min || root->data>max)
        return false;
    
    bool isLeftOk = isBST3(root->left,min, root->data-1); // -infinity to (n-1) where root->data=n
    bool isRightOk = isBST3(root->right,root->data,max);

    return isLeftOk && isRightOk ;
}

int main()
{   // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
    // 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
    //4 2 6 1 30 5 7 -1 -1 -1 -1 -1 -1 -1 -1
    BinaryTreeNode<int>* root = takeInputLevelWise();
    printLevelWise(root);
    cout<<endl;
    cout<<isBST(root)<<endl;
    cout<<isBST3(root);
    delete root;
}

