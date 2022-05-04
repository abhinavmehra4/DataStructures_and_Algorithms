#include<iostream>
#include<climits>
using namespace std;
class stackUsingArrays
{
    int *data; //pointer object
    int nextIndex;
    int capacity;

    public:

    stackUsingArrays(int totalSize)
    {
        data = new int[totalSize]; // the pointer object is defined as a dynamically created array
        nextIndex =0;
        capacity = totalSize;
    }

    int size()
    {
        return nextIndex;
    }
    bool isEmpty()
    {
        return nextIndex==0;
    }
    void push(int element)
    {
        if(nextIndex==capacity)
        {
            cout<<"STACK FULL \n";
            return;
        }
        
        data[nextIndex]=element;
        nextIndex++;
    }
    int pop()
    {
        if(isEmpty())
        {
            cout<<"STACK EMPTY\n";
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
        
    }
    int top()
    {   if(isEmpty())
        {
         cout<<"STACK EMPTY\n";
         return INT_MIN;   
        }
        return data[nextIndex-1];
    }

};

