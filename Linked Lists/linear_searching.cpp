//this searching one will be executed throught the of functions
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

int main()
{
    /* Start with the empty list */
    Node* head = NULL;
    int x = 21;
 
    /* Use push() to construct below list
    14->21->11->30->10 */
    //As clearly visible, enter the code in a reverse order of the linked list.
    push(&head, 10);
    push(&head, 30);
    push(&head, 11);
    push(&head, 21);
    push(&head, 14);

    printList(head); //we dont have to put & because head already stores an address and we don't want to pass the address
   // of 'head' as the parameter. But intead we wanna pass the address it stores.

    cout<<endl;
    search(head,x) ? cout<<"Yes" : cout<<"No";

    return 0;
}