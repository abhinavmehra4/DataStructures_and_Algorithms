#include<iostream>
#include "Node.cpp"
using namespace std;

Node* takeInput()
{
    int data;
    cin>>data;
    Node* head = NULL; //This shows that the linked list is empty.
    //this function, takes input from the user and converts it into a linked list and finally returns the head
    //But how many nodes do we need? 
        //So we could either ask the user after every input if they want to add another node by asking yes or no
        //or we can use a terminator -1. Here nodes will continuously be created with every input until the user 
        //enters -1, which terminates the linked list
    while(data!=-1)
    {
        /*
    Because Node is statically created, it gets destroyed after every iteration. So instead we should 
    use dynamic allocation because the node wont be deleted until specified.

        Node n(data); //static creation of a node
        if(head==NULL)
            head = &n; //With this, only the first term will be made the head and not others
        cin>>data;
        */
       Node* newNode = new Node(data);
       if(head==NULL)
       {head=newNode;}
       else{
           Node* temp = head;
           while(temp->next!=NULL)
           {
               temp=temp->next;
           }
           temp->next=newNode;
       }
       cin>>data;
    }
    return head; 
}

Node* takeInputBetter()
{
    int data;
    cin>>data;
    Node* head= NULL;
    Node* tail = NULL;


    while(data!=-1)
    {
        Node* newNode = new Node(data);

        if(head==NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next=newNode;
            tail=tail->next;
            //OR
            // tail = newNode;
        }
        cin>>data;
    }
    return head;
}

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

Node* insertNode(Node* head,int i, int data)
{
    Node* newNode = new Node(data); //created a node
    Node* temp=head;
    int count=0;

//Inserting at the beginning
if(i==0)
{
    newNode->next=head;
    head=newNode;
    return head; //so that the head gets updated in the original
}

//Inserting at the middle or end

    while(temp!=NULL && count<i-1)
    {
        //After the while loop, we will arrive at the node, just after which we have to insert a node
        temp=temp->next;
        count++;
    }
    if(temp!=NULL)
    {
        newNode->next=temp->next;
        temp->next=newNode;
    }
    //or
    // Node* a = temp->next;
    // temp->next=newNode;
    // newNode=a;

    return head; //the original head is returned in case, node is inserted at the middle
}

int main()
{
 //Using UserInput Function
 Node* head = takeInput(); //important way
 print(head);
 int i,data;
 cout<<endl<<"Enter the position and data ";
 cin>>i>>data;
 head = insertNode(head,i,data);
 //Using input function with better time complexity
print(head);
    return 0;
}