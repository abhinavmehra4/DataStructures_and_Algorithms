#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int key;
    Node* next;
};
void push(Node** head_ref,int new_key)
{
    Node* new_node = new Node();
    new_node->key=new_key;
    new_node->next=(*head_ref);
    (*head_ref)= new_node;
}
void printList(Node* n)
{
    while(n!=NULL)
    {
        cout<<n->key<<" ";
        n=n->next;
    }
}

void insertBeginning(Node** head_ref,int n) //same as the push function
{
    Node* new_node = new Node();
    new_node->key=n;
    new_node->next=(*head_ref);
    (*head_ref)=new_node;
}

void insertEnd(Node** head_Ref, int n)
{
    Node* new_node = new Node();
    new_node->key=n;
    new_node->next=NULL;
    Node* last = new Node();
    if(last==NULL)
    {
        last=new_node;
        return;
    }
    while(last->next!=NULL)
    {
        last=last->next;
    }
    last->next= new_node;
    return;
}

void insertBetween(Node* prev_node,int n)
{
    if(prev_node==NULL)
    {
    cout<<"This node cannot be a NULL";
    return;
    }
    Node* new_node = new Node();
    new_node->key=n;
    new_node->next=prev_node->next;
    prev_node->next=new_node;

}

int main()
{

Node* head = NULL;


    return 0;
}