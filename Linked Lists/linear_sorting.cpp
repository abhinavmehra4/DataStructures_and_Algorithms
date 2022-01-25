#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
public:
int key;
Node* next;
};

//We create a function which creates the nodes and allocates memory.
void push(Node** head_ref, int new_key )
{
   //for explanation, check the notebook
    Node* new_node = new Node(); //allocate memory to a node
    new_node->key=new_key; //value of the Node is fed in
    new_node->next = (*head_ref); // address of the next node is also fed in.
    (*head_ref) = new_node; // all the nodes created are linked together using this.
}
void printList(Node* n)
{
    while (n != NULL) {
        cout << n->key << " ";
        n = n->next;
    }
}

/*void sort(Node** head_ref)
{
    Node* current = new Node();
    current = (*head_ref);
    Node* index = new Node();
    index=NULL; 

    if(current==NULL)
    {
        return;
    }
    else{
    while(head_ref!=NULL)
    {
        index=current->next;
        while(index!=NULL)
       { if(current->key>index->key)
        {
            int temp;
            temp = index->key;
            index->key=current->key;
            current->key=temp;
        }
        index=index->next;
       }
       current=current->next;
    }
    }
}
*/
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

    printList(head);
    sortLinkedList(&head);
    cout<<"hey";
    cout<<endl;
    printList(head);
    cout<<"hey";

    
    return 0;
}
