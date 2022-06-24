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