#include<iostream>
using namespace std;
#define n 100
class queue
{
    int* arr; int front, back;
    public:
    queue()
    {
        arr = new int[n];
        front=-1;
        back=-1;
    }

    void enqueue(int x) //when entering back goes ++. 
    {
        if(back==n-1)
        {
            cout<<"Queue Overflow\n";
            return;
        }
        if(front==-1)//this is only for the first push
        {
            front++;
        }
        else
        arr[++back]=x;
    }

    void dequeue() //when leaving the front goes ++ to remove existence of the previous stack elements
    {
        if(front==-1 || front>back)
        {
            cout<<"Queue underflow\n";
            return;
        }
        front++; 
    }
    int peek()
    {
        if(front==-1 || front>back)
        {
            cout<<"Queue underflow\n";
            return -1;
        }
        return arr[front];
    }
    bool empty()
    {
        if(front==-1 || front>back)
        {
            return true;
        }
        else 
        return false;
    }
};
int main()
{
    
    return 0;
}