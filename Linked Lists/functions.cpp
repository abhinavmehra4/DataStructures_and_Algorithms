#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{

public:
int key;
Node* next;

};

void push(Node** head_ref,int new_key ){

Node* new_node = new Node();

new_node->key=new_key;
new_node->next=(*head_ref);

(*head_ref) = new_node;
}

void print(Node* n)
{
    while(n!=NULL)
    {
        cout<<n->key<<" ";
        n=n->next;

    }
}

void insertBeginning(Node** head_ref, int n)
{
  Node* new_node = new Node();
     
    new_node->key=n;
    new_node->next=(*head_ref);
    (*head_ref) = new_node;
  
}
void insertEnd(Node** head_ref, int n)
{
  Node* new_node = new Node();
     
    new_node->key=n;
    new_node->next=(*head_ref);
    (*head_ref) = new_node;
  
}

int main()
{
    Node* head = NULL;
    //2 4 6 8 10
    push(&head,10);
    push(&head,8);
    push(&head,6);
    push(&head,4);
    push(&head,2);

    print(head);

    cout<<endl<<"Inserted at the beginning\n";

    insertBeginning(&head,9);

    print(head);

    return 0;

    
}
