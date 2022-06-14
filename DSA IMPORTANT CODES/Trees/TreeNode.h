//this file will not be compiled and will only be used in another class for its class details.
#include<iostream>
#include<vector>
using namespace std;
template <typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode*> children; //inside the nodes of the trees we will be storing the children
    //And these children are nothing but pointers of the tree nodes pointing to their children. 
    //Therfore they will have 'data' as well as their own 'children' vector pointers of type 'TreeNode'
    // THEREFORE, CHILDREN IS OUR VECTOR. AND THIS VECTOR WILL ONLY RECEIVE POINTERS

    /*
        but there is a catch. Since TreeNode is template, so got to specify. Hence we should have done
        
        vector<TreeNode<T>*> children;

        however, if we just did this " vector<TreeNode*> children; ", C++ will automatically assume that the children are of same 
        type as the tree node. Hence we dont have to specify.

    */
   TreeNode(T data)
   {
       this->data=data;
   }
   ~TreeNode(){
       for(int i =0;i<root->children.size();i++)
       {
           delete children[i];
       }
   }
};

