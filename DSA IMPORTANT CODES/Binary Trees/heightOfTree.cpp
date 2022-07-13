#include<iostream>
#include "BinaryTreeNode.h"
#include<queue>
#include<vector>
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

int numNodes(BinaryTreeNode<int>* root)
{
    if(root==NULL)
        return 0;
    return 1 + ( numNodes(root->left) + numNodes(root->right));
    

}

int height(BinaryTreeNode<int>* root)
{
    // Write our code here
    if(root==NULL)
        return 0;
    
    int left = 1+height(root->left); //1 corresponds to the root
    int right = 1+height(root->right); //1 corresponds to the root
    if(left>right)
        return left;
    else
        return right;
}



int main()
{   // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
    BinaryTreeNode<int>* root = takeInputLevelWise();
    printLevelWise(root);
    cout<<"Number of Nodes "<< numNodes(root);
    
    delete root;
}

/*

/**********************************************************

	Following are the Binary Tree Node class structure and
	the Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

	template <typename T>
	class Node {
		public:
    	T data;
    	Node<T> *next;
    	Node(T data) {
        	this->data=data;
        	this->next=NULL;
    	}
	}:

***********************************************************/
/*
#include<vector>
#include<queue>
vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    // Write your code here
    vector<Node<int>*> temp_vector;
    if(root==NULL) //in case the root is NULL
    {
        temp_vector.push_back(NULL);
        return temp_vector;
    }
    
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    Node<int>* head=NULL;
    Node<int>* tail=NULL;
    while(pendingNodes.size()!=0)
    {
        BinaryTreeNode<int>*front = pendingNodes.front();
        pendingNodes.pop();
        
        if(front==NULL)
        {	
            tail->next=NULL;
            if(pendingNodes.size()==0)
            {
                break;
            }
            else
            {
                pendingNodes.push(NULL);
                head=NULL;
                tail=NULL;
            }
               
        }
        else
        {
        	Node<int>* node = new Node<int>(front->data);  
            
        
        
        if(head==NULL and tail==NULL)
        {
            
            head = node;
            tail = node;
            temp_vector.push_back(head);
            
        }
        else if(head!=NULL && tail!=NULL)
        {
            tail->next=node;
            tail=node;
            
        }
        
        if(front->left!=NULL)
            pendingNodes.push(front->left);
        else if(front->right!=NULL)
            pendingNodes.push(front->right);
        
    }
    
    }
    return temp_vector;
    //remember to push the head into the vector everytime the linked list is fully linked
}

*/