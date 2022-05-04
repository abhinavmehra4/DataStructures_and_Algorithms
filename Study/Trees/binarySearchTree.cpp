#include<iostream>
using namespace std;

class Node{
public:
int data;
Node *left, *right;
};

Node* createNode(int val)
{
    Node* node = new Node();
    node->data = val;
    node->left=node->right=NULL;
    return node;
}

int main()
{


    return 0;
}