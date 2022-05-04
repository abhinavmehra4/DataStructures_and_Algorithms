#include<iostream>
#include "Node.cpp"
using namespace std;

void print(Node* head)
{
    Node* temp = head; // We do this, so the value of head does not change and the address of the head is not lost
    //But this does not matter as the original value of head remains unchanged because only the value was passed
    while(temp!=NULL)
    //to stop at the LAST node we use "head->next!=NULL"
   {
    cout<<temp->data<<" ";
    temp=temp->next;
   } 
}

int main()
{
/*
    //Statically printing the values
    Node n1(1);
    Node n2(2);
    Node n3(3);
    Node n4(4);
    Node n5(5);
    Node* head = &n1;
    
    n1.next=&n2;
    n2.next=&n3;
    n3.next=&n4;
    n4.next=&n5;

    print(head);
    cout<<endl;
    print(head); //value of head is what it was initially and does not change to NULL

*/

/*
    //DYNAMICALLY PRINTING A LINKED LIST

    Node* n1 = new Node(10);
    Node* n2 = new Node(20);
    Node* n3 = new Node(30);
    Node* n4 = new Node(40);
    Node* n5 = new Node(50);

    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5;

Node* head = n1;

    print(head);
  */ 

    return 0;
}