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
int length(Node *head) {
    // Write your code here
    
    if(head==NULL)
    {
        return 0;
    }
    
    int num = length(head->next);
    return num+1;
    
}

Node *appendLastNToFirst(Node *head, int n)
{
    if(head==NULL || n==0){ //this is the base case
        return head;
    }
    Node* temp=head; //initialize the Node variable
    Node* tail=NULL;
    Node* newHead=NULL;
    int len = length(head); //get number of nodes of the linked list
    //Write your code here
   int x = len-n; //nodes to remove from the starting
    
    int count=0;
    while(count<x-1 && temp!=NULL)
    {
        temp=temp->next;
        count++;
    } //temp becomes the last node of detachment
    
    tail=temp; //temp becomes the tail
    newHead = temp->next; //temp ka next becomes the new head
    tail->next=NULL; //connec the tail to NULL
    
    
    Node* temp2 = newHead;
    while(temp2->next!=NULL)
    {
        temp2=temp2->next;
    }
    
    temp2->next=head;
    
    return newHead;
    
    
}
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

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int n;
		cin >> n;
		head = appendLastNToFirst(head, n);
		print(head);
	}
	return 0;
}