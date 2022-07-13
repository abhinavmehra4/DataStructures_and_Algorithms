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
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
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

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    //Write your code here
    Node* fH=NULL;
    Node* fT=NULL;
     if(head1!=NULL&&head2==NULL)
    {
        return head1;
    }
    else if(head1==NULL&&head2!=NULL)
    {
        return head2;
    }
    else if(head1==NULL&&head2==NULL)
    {
        return NULL;
    }
    
    //INITIALIZING THE HEAD
    if(head1->data<=head2->data)
    {
        fT=head1;
        fH=head1;
        head1=head1->next;
    }
    else 
    {
     	fT=head2;
        fH=head2;
        head2=head2->next;
    }
    
    //WHEN BOTH OF THEM ARE NOT NULL
    while(head1!=NULL && head2 !=NULL)
    {
        if(head1->data<=head2->data)
        {
            fT->next=head1;
            fT=head1;
            head1=head1->next;  
        }
       else{
            fT->next=head2;
            fT=head2;
           head2=head2->next;
        }
    }
    
    //This is for the scenario when one of them becomes NULL first
    while(head1==NULL && head2!=NULL)
    {
        fT->next=head2;
        fT=head2;
    head2=head2->next;
    }
    while(head2==NULL && head1!=NULL)
    {
        fT->next=head1;
        fT=head1;
        head1=head1->next;
    }
    return fH;
    
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head1 = takeinput();
		Node *head2 = takeinput();
		Node *head3 = mergeTwoSortedLinkedLists(head1, head2);
		print(head3);
	}
	return 0;
}