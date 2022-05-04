#include<iostream>
using namespace std;

class node{
  
public:
node* next; int data;
  node(int val)
  {
    data=val;
    next=NULL;
  }
};
void insertAtTail(node* &head,int val)
{
  node* n = new node(val);

    if(head==NULL)
    {head=n;
    return;}

  node* current =head;
  while(current->next!=NULL)
  {
    current=current->next;
  }
  current->next=n;
}
void insertAtHead(node* &head,int val)
{
  node* n = new node(val);
  n->next=head;
  head=n;
}
void display(node* head)
{
  node* current=head;
  while(current!=NULL)
  {
    cout<<current->data<<"->";
    current=current->next;
  }
  cout<<"NULL"<<endl;
}
int count(node* head)
{ node* current = head;
  int count=0;

  if(head==NULL)
  {
    return 0;
  }

  while(current!=NULL)
  {
    count++;
    current=current->next;
  }
  return count;
}
void delete_start(node* &head)
{
  if(head==NULL)
  {
    cout<<"There is no node to delete\n";
    return;
  }
  if(head->next==NULL)
  {
    head==NULL;
  }
  head=head->next;
}
void delete_end(node* &head)
{
  node* current = head;
  while(current->next->next!=NULL)
  {
    current = current->next;
  }
  current->next=NULL;
}

void delete_middle(node* &head,int k)
{
    
    node* current = head;
    int count=1;
    while(current!=NULL)
    {
        
        if(k==count+1)
        {
            current=current->next->next;
            return;
        }
        count++;
        current=current->next;
        
    }
}
int main()
{
  node* head=NULL;
  insertAtTail(head,1);
  insertAtTail(head,2);
  insertAtTail(head,3);
  insertAtTail(head,4);
  insertAtTail(head,5);
  insertAtTail(head,6);
  insertAtTail(head,7);

  display(head);

  cout<<"The number of nodes are "<<count(head)<<endl;
  delete_start(head);
  display(head);
  delete_end(head);
  display(head);
  delete_middle(head,3);
  display(head);

  return 0;
}
