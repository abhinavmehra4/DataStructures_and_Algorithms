#include<iostream>
using namespace std;

class Node{
public:
int data;
Node *left, *right;


};

Node* newNode(int data)
{
    Node* node = new Node();
    node->data = data;
    node->left=NULL;
    node->right = NULL;
    return node;
}

void preorderTravers(Node* node)
{
    if(node!=NULL)
    {
        cout<<node->data<<"->";
        preorderTravers(node->left);
        preorderTravers(node->right);
        
    }
}
void postorderTravers(Node* node)
{
    if(node!=NULL)
    {
        
        postorderTravers(node->left);
        postorderTravers(node->right);
        cout<<node->data<<"->";
    }
}
void inorderTravers(Node* node)
{
    if(node!=NULL)
    {
        inorderTravers(node->left);
        cout<<node->data<<"->";
        inorderTravers(node->right);
        
    }
}
int main()
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);

    cout<<"\npreorder traversal\n";
    preorderTravers(root);

    cout<<"\npostorder traversal\n";
    postorderTravers(root);

    cout<<"\ninorder traversal\n";
    inorderTravers(root);
    return 0;
}