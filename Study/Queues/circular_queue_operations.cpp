#include<iostream>
using namespace std;

#define MAX 500

class queue{

int item[MAX],front,rear;

public:
queue()  {front=-1;
          rear=-1;}
bool isFull()
{
     if((front==0)&&(rear=(MAX-1)))
     return true;
     if(front==rear+1)
     return true;
     else
     return false;

}
 bool isEmpty()
    {   //because when a queue has its first element, front becomes 0.
        if(front==-1)
        return true;
        else
        return false;
    }


void enqueue(int x)
{
    if(isFull())
        {
            cout<<"Queue is full/n";
        }
    else
    {
         if (front==-1)
            {front=0;}
        
        rear = (rear+1)%MAX;
        rear=0;
        item[rear]=x;
        cout<<endl<<"The item inserted is "<<x<<endl;
        
    }
   
}

void dequeue(int x)
{
    if(isEmpty())
    {
        cout<<"The queue is empty\n";
    }
    if(front>=rear)
    {
        front=-1;
        rear=-1;
    }
    else
    {
        front++;
    }
}

};

int main()
{

    return 0;
}