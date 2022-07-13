#include<iostream>
#include "BinaryTreeNode.h"
using namespace std;

class BST{

    BinaryTreeNode<int>* root; //private

    public:
        BST(){
            root==NULL;
        }
        ~BST(){
            delete root;
        }

        void insert(int data)
        {

        }

        void deleteData(int data)
        {

        }
    private:
        bool hasData(int data, BinaryTreeNode<int>* root)
            {
                if(root==NULL)
                    return false;
                if(root->data==data)
                    return true;
                else{
                    if(root->data>data)
                        return hasData(data,root->left);
                    else
                        return hasData(data,root->right);
                }
            }
    public:
        bool hasData(int data)
        {
            return hasData(data,root);            
        }
     
};

/*

#include<queue>
#include<climits>
#include<algorithm>
class BST {
    // Define the data members
    BinaryTreeNode<int>* root; //private
   public:
    BST() { 
        // Implement the Constructor
        root=NULL;
    }
    ~BST(){
        delete root;
    }

	/*----------------- Public Functions of BST -----------------*/
	/*
    private:
    int minimum(BinaryTreeNode<int>* root)
        {
            if(root==NULL)
                return INT_MAX; //positive infinity
            return min(root->data,min(minimum(root->right),minimum(root->left)));
        }
    BinaryTreeNode<int>* remove(int data, BinaryTreeNode<int>* root)
    {
        if(root==NULL)
        	return NULL;
        if(root->data>data)
        {
            BinaryTreeNode<int>* new_root = remove(data,root->left);
            return new_root;
        }
        else if(root->data<data)
        {
            BinaryTreeNode<int>* new_root = remove(data,root->right);
            return new_root;
        }
        else{
            if(root->left==NULL && root->right==NULL)
            {
                delete root;
                return NULL;
            }
            else if( root->left==NULL && root->right!=NULL)
            {
                BinaryTreeNode<int>* new_root = root->right;
                //root->right==NULL;
                delete root;
                return new_root;
            }
            else if(root->left!=NULL && root->right==NULL)
            {
                BinaryTreeNode<int>* new_root = root->left;
                //root->left = NULL;
                delete root;
                return new_root;
            }
            else
            {
                

                BinaryTreeNode<int>* minnode=root->right;
                while(minnode->left!=NULL)
                    minnode=minnode->left;
                int rightmin=minnode->data;
                root->data=rightmin;
                root->right=remove(rightmin,root->right); 
                return root; 
				

            }
        }
    }
    public:
    void remove(int data) { 
        // Implement the remove() function 
        this->root = remove(data,root);
    }

    
    //PRINT FUNCTION
    private:
void printTree(BinaryTreeNode<int>* root)
{
    if(root==NULL)
        return;
    cout<<root->data<<":";
    if(root->left)
    {
        cout<<"L:"<<root->left->data<<",";
    }
    if(root->right)
    {
        cout<<"R:"<<root->right->data;
    }
    cout<<endl; //for moving on to the next subtree
    printTree(root->left);
    printTree(root->right);
}
	public:
    void print() { 
        // Implement the print() function
        printTree(root);
    }
    
    //INSERT FUNCTION
	private:
    BinaryTreeNode<int>* insert(int data, BinaryTreeNode<int>* root)
    {
        if(root==NULL)
        {
            BinaryTreeNode<int>* new_node = new BinaryTreeNode<int>(data);
            return new_node;
        }
        else{
            if(root->data>=data)
            {
                BinaryTreeNode<int>* leftNode = insert(data,root->left);
                root->left=leftNode;
            }
            else if(root->data<data)
            {
                BinaryTreeNode<int>* rightNode = insert(data, root->right);
                root->right = rightNode;
            }
            
        }
        return root;
    }
    public:
    void insert(int data) 
    { 
        // Implement the insert() function 
        this->root = insert(data,root);
    }
    
    //SEARCH FUNCTION
    private:
    bool search(int data, BinaryTreeNode<int>* root)
    {
        if(root==NULL)
            return false;
        if(root->data==data)
            return true;
        else
        {
            if(root->data>data)
                return search(data,root->left);
            else
                return search(data, root->right);
        }
    }
    public:
    bool search(int data)
    {
		// Implement the search() function 
        return search(data, root);
    }
};



*/
