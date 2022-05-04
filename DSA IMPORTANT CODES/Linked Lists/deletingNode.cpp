#include<iostream>
using namespace std;
#include "Node.cpp"

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

Node* deleteNode(Node* head, int i)
{
    Node* temp = head;
    int count=0;

    if(i==0)
    {
        head=head->next;
        return head;
    }
    while(temp!=NULL&&count<i-1)
    {
        temp=temp->next;
        count++;
    }
    if(temp!=NULL)
    {
        Node* a = temp->next;
        Node* b = a->next;
        temp->next=b;
        delete a;
    }
    return head;
}

Node *deleteNodeRec(Node *head, int pos) {
	//Write your code here
    
    //BASE CASE
    if(head==NULL)
        return head;
    
    //SMALL CALCULATION
    if(pos==0)
    {
        head=head->next;
        return head;
    }
    
    //RECURSIVE CALL
    Node* x = deleteNodeRec(head->next,pos-1);
    head->next=x;
    return head; 
    /*
    But if the recursive call is 

    Node* x = deleteNodeRec(head->next,pos-1);
    return x;

    The head of the linked list in this case will be the immedietly next node of the deleted node.
    
    */
}

int main()
{
 //Using UserInput Function
 Node* head = takeInput(); //important way
 print(head);
 
cout<<"\nEnter the position you want to delete \n";
int pos;
cin>>pos;
head = deleteNode(head,pos);
print(head);

cout<<"\nEnter the position you want to delete \n";
int i;
cin>>i;
head = deleteNodeRec(head,i);
print(head);

    return 0;
}