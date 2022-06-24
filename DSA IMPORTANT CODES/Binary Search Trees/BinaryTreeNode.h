#include<iostream>
using namespace std;
template <typename T>

class BinaryTreeNode{

    public:
        T data;

        //since we didnt include the template T, we can say that the ledt and right node of the BT can be of 
        //any data type and does not have to be of the same type
        BinaryTreeNode* left;
        BinaryTreeNode* right;

        BinaryTreeNode(T data)
        {
            this->data = data;
            left = NULL;
            right = NULL; //because we should not leave this to be a garbage value
        }
        ~BinaryTreeNode()
         {
             delete left;
             delete right;
            //in the above two lines even if the compiler encounters 'delete NULL' it won't raise a flag and we will be good.
        }

};