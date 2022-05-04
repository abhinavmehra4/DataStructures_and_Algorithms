#include<iostream>
using namespace std;

class Node{

public:

int data;
Node *left, *right;
Node(int data)
{
    this->data=data;
    left=right=NULL; //default point to NULL
}

};

//PREORDER TRAVERSAL
void preorderTraversal(Node* node)
{
    if(node==NULL)
        return;
    cout<<node->data<<"->";
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

//POSTORDER TRAVERSAL
void postorderTraversal(Node* node)
{
    if(node==NULL)
        return;
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    cout<<node->data<<"->";

}

//INORDER TRAVERSAL
void inorderTraversal(Node* node)
{
    if(node==NULL)
        return;
    
    inorderTraversal(node->left);
    cout<<node->data<<"->";
    inorderTraversal(node->right);
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(12);
    root->right = new Node(9);
    root->left->left = new Node(5);
    root->left->right = new Node(6);

    cout<<"\nInorder Traversal\n";
    inorderTraversal(root);
    
    cout<<"\nPreorder Traversal\n";
    preorderTraversal(root);

    cout<<"\nPostorder Traversal\n";
    postorderTraversal(root);


    return 0;
}