#include<iostream>
using namespace  std;

class Node{
    
public:
Node* next;
int data;

    Node(int data){
        next=NULL;
        this->data=data;
    }
};

class Stack
{
    Node* head;
    int size;

    public:
    Stack(){
        size=0;
        head=NULL;
    }

    int getSize(){
        return size;
    }

    void push(int element){
        Node* newNode = new Node(element);
        head->next=newNode;
        size++;

    }

    void pop(){
        head=head->next;
        size--;
    }

    int top(){
        return head->data;
    }

    bool isEmpty(){
        return head==NULL;
    }

};

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout<<s.top()<<endl;
    s.pop();
    s.pop();
    cout<<s.top()<<endl;

    cout<<s.getSize()<<endl;
    cout<<s.isEmpty()<<endl;
    return 0;
}