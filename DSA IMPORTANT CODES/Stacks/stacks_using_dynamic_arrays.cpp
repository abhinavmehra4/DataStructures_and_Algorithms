#include<iostream>
#include<climits>
using namespace std;
class stackUsingArrays
{
    int *data; //pointer object
    int nextIndex;
    int capacity;

    public:

    stackUsingArrays()
    {
        data = new int[4]; // the pointer object is defined as a dynamically created array
        nextIndex =0;
        capacity = 4; //We decided this ourselves
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
            /*cout<<"STACK FULL \n";
            return;*/
            //Once the stack is full, we create a new array dynamically with double the size of the previous one

            //INCREASING SIZE OF THE DYNAMIC ARRAY
            int* newData = new int[2*capacity];
            for(int i =0;i<capacity;i++)
            {
                newData[i]=data[i];
            }
            capacity *= 2;
            delete [] data ;
            data = newData;
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

