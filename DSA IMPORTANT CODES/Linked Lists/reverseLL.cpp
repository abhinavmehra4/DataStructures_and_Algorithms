#include <iostream>

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

using namespace std;

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
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

void printReverse(Node *head)
{

    Node* curr = head;
    Node* prev = NULL;
    Node* nex = NULL;
    
    
    
    //BASE CASE
    
    if(curr==NULL)
    {
        print(head);
        return;
    }
    
    //WHEN THERE IS ONLY 1 TERM IN THE LINKED LIST
    if(head->next==NULL)
    {
        print(head);
        return;
    }
    
    //Remainder of the code

     while(curr!=NULL)
    {
       
        nex=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nex;
    }
    head=prev;
    print(head);
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		printReverse(head);
		cout << endl;
	}
	return 0;
}