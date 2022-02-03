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

//Allocating memory to the pointers

    one = new Node();
    two = new Node();
    three = new Node();

//Adding values 

one->value=1;
two->value=2;
three->value=3;

//Linking the nodes

one->next=two;
two->next=three;
three->next=NULL;

//printing the value of the linked list

head = one; // Since address of the first node is called HEAD, equate the pointers and corresponding to that so will the values we equated.

while(head!=NULL)
{
    cout<< head->value <<endl;
    head = head->next;
}

    return 0;
}