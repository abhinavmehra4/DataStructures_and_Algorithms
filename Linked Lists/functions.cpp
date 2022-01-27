#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{

public:
int key;
Node* next;

};

void push(Node** head_ref,int new_key ){
//we pass a reference to head so as to not change the position of head
Node* new_node = new Node();

new_node->key=new_key;
new_node->next=(*head_ref);
(*head_ref) = new_node;
}

void print(Node* n) 
//this function will work the from start to end, iff
//you dont change the head from the first node to some other node
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
  Node* new_add = new Node();
  //add data to the node we want to add
  new_add->key=n;
  //This new node is going to be the last node, 
  //so make next of  it as NULL
  new_add->next=NULL;
  Node* last = new Node();
  last = (*head_ref) ;
//If the Linked List is empty, then make the new node as head
  if(last==NULL)
  {
    last = new_add;
    return; //this return helps the user break out of the function.
    //and this way 'return' can only be used in 'void' type functions
  }
// Else traverse till the last node
  while(last->next!=NULL)
  {
    last=last->next; //keeps shifting to the next node;
  }
// then Change the next of last node to the node we wantedd to add.     
    last->next=new_add;
    return;
}

void insertBetween(Node* prev_node,int n)
{
  // 1. Check if the given prev_node is NULL
    if (prev_node == NULL) 
    { 
        cout << "The given previous node cannot be NULL"; 
        return; 
    }
  Node* new_node = new Node();
  new_node->key=n;
  // 4. Make next of new node as next of prev_node
    new_node->next = prev_node->next; 
  // 5. move the next of prev_node as new_node
    prev_node->next = new_node; 
}
bool search(Node* c, int s)
{
    Node* current = c;
    while(current!=NULL)
    {
        if(current->key==s)
        {return true;}
        current = current-> next;

    }
    return false;
    
}
void sortLinkedList(Node** head_ref) {
  Node* current = new Node();
  Node* index = new Node();
  current = (*head_ref);
  index = NULL;
  int temp;

  if (head_ref == NULL) {
  return;
  } else {
  while (current != NULL) {
    // index points to the node next to current
    index = current->next;

    while (index != NULL) {
    if (current->key > index->key) {
      temp = current->key;
      current->key = index->key;
      index->key = temp;
    }
    index = index->next;
    }
    current = current->next;
  }
  }
}
int main()
{
    Node* head = NULL;
    push(&head,2);
    push(&head,6);
    push(&head,10);
    push(&head,4);
    push(&head,8);

    print(head);

    cout<<endl<<"Inserted at the beginning\n";

    insertBeginning(&head,9);

    print(head);
    cout<<endl;
    insertEnd(&head,45);
    print(head);
    cout<<endl;
    insertBetween(head->next->next->next,78);
    print(head);

    return 0;

    
}
