#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{

public:
int value;
Node* next;

};

int main()
{
    Node* head;
    Node* one = NULL;
    Node* two = NULL;
    Node* three = NULL;

//Allocating memory dynamically

    one = new Node();
    two = new Node();
    three = new Node();

//Adding values to the node

    one->value=1;
    two->value=2;
    three->value=3;

//Linking  the nodes

    one->next=two;
    two->next=three;
    three->next=NULL;
//Output of the linked list

    head=one;

    while(head!=NULL)
    {
        cout<<head->value<<endl;
        head=head->next;
    }
/* INSERTION IS DONE AT THE BEGINNING
Node* five = NULL;

five = new Node();
five->value=5;

head=five; 

five->next=one;

cout<<"new order is \n";
    while(head!=NULL)
    {
        cout<<head->value<<endl;
        head=head->next;
    }

*/
/* INSERTION IS DONE AT THE END
Node* five = NULL;

five = new Node();
five->value=5;
head=one;
// this is written here because we need head to go back to the first node. in insertion at the beginning
//we did not hae to specifically do this. It was done by default.
five->next=NULL;; 
three->next=five;
cout<<"new order is \n";
    while(head!=NULL)
    {
        cout<<head->value<<endl;
        head=head->next;
    }

*/
cout<<"The new order is\n";
/*INSERTION IN THE MIDDLE, AFTER THE NODE2*/

Node* five = NULL;

five = new Node();
five->value=5;
five->next=three;

two->next=five;

head = one;
while(head!=NULL)
{
    cout<<head->value<<endl;
    head=head->next;
}

    return 0;
}