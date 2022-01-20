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
    Node* four = NULL;
    Node* five = NULL;

//Allocating memory dynamically

    one = new Node();
    two = new Node();
    three = new Node();
    four = new Node();
    five = new Node();

//Adding values to the node

    one->value=1;
    two->value=2;
    three->value=3;
    four->value=4;
    five->value=5;

//Linking  the nodes

    one->next=two;
    two->next=three;
    three->next=four;
    four->next=five;
    five->next=NULL;
//Output of the linked list

    head=one;

    while(head!=NULL)
    {
        cout<<head->value<<endl;
        head=head->next;
    }

//Deleting from the middle- NODE 3
cout<<"Middle node is deleted"<<endl;
two->next=four;
delete three ;
head=one;

    while(head!=NULL)
    {
        cout<<head->value<<endl;
        head=head->next;
    }
//Deleting from beginning- NODE1
head=two;
delete one;
cout<<"Node at the beginning is deleted\n";
 while(head!=NULL)
    {
        cout<<head->value<<endl;
        head=head->next;
    }
//Deleting from end- NODE5
head=two;
four->next=NULL;
delete five;
cout<<"Node at the end is also deleted now\n";
while(head!=NULL)
    {
        cout<<head->value<<endl;
        head=head->next;
    }

return 0;
}