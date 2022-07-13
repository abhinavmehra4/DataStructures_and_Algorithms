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


Node *removeDuplicates(Node *head)
{
    //BASE CASE
    if(head==NULL){
        return head;
    }
    
    Node *t1,*t2; //creating 2 pointers
    t1=head; //first points to head
    t2=t1->next; //second points to the next node of head
    
    while(t2!=NULL)
    {
        if(t1->data==t2->data)
        {
            t2=t2->next;
            continue;
        }
        if(t1->data!=t2->data)
        {
            t1->next=t2;//connecting the nodes
        }
        
        // if(t2->next==NULL)
        // {
        //     t1->next=t2;
        //     break;
        // }

        t1=t2; //move t1 qnd t2 ahead after the duplicacy is removed
        t2=t1->next;
    }
    
    //After the loop, t2 becomes NULL and t2 becomes the last element of the linked list. 
    //And this element must be finally point to NULL to complete th elinked list
    t1->next=NULL;
    return head;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		head = removeDuplicates(head);
		print(head);
	}
	return 0;
}