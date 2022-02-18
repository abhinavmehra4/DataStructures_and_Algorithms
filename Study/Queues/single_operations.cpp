#include<iostream>
using namespace std;
#define MAX 500

class queue{
    int front,rear,items[MAX];
    public:

    queue()
    {
        front=-1;
        rear=-1;
    }

    bool isFull()
    {
        return (rear==(MAX-1)&&front==0);
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
        if (front==-1)
            {front=0;}

        rear++;
        items[rear]=x;
    }

    void dequeue()
    {   int element;
        if(isEmpty())
        {
            cout<<"Queue is empty\n";
            //return -1;
        }

        else
        {
            element = items[front];//the value at the front is assigned
            if(front>=rear)
            //if queue has only one element, reset the queue to its initial state
            {
                front=-1;
                rear=-1;
            }
            else
            {
                front++;
            }
            cout<<endl<<"The deleted element is "<<element<<endl;
            //return element;
        }
    }

    void display()
    {
        if(isEmpty())
            cout<<"Queue is empty\n";
        else{
            cout<<"Front index is "<<front<<endl;
            for(int i=front;i<=rear;i++)
            {
                cout<<items[i]<<" ";
            }
            cout<<endl<<"Rear index is "<<rear<<endl;
        }
        
    }

};
int main()
{
    queue q;

  //deQueue is not possible on empty queue
  q.dequeue();

  //enqueue 5 elements
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.enqueue(4);
  q.enqueue(5);

  // 6th element can't be added to because the queue is full
  q.enqueue(6);

  q.display();

  //deQueue removes element entered first i.e. 1
  q.dequeue();

  //Now we have just 4 elements
  q.display();

    return 0;
}