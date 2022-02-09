#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define MAX 1000
class Stack{
    int top;
public:
    int a[MAX]; //Maximum size of the stack
    Stack(){ top = -1; }//A constructor is created so that every time a stack is created, it is
    //initialised to -1 
    bool push(int x)
        {
                //before pushing one must check if the stack is full
                if(top>=MAX-1)
                {
                    cout<<"Stack Overflow";
                    return false;
                }
                else
                {
                    a[++top]=x; //Since value of top is same as index of the array
                    //in the above step, value was stored in the stack as well as an increment in the value of top took place.
                    cout<< x <<" was pushed into the stack\n";
                    return true;
                }
            
    
        }
    int pop()
        //this function returns the value that is to be popped
            {
                //before popping we must check if the stack is already empty or not
                if(top<0)
                {
                    cout<<"Stack underflow\n";
                    return 0;
                }
                else
                {
                    int x = a[top--]; //simultaneously value of top is decreased.
                    return x;
                }
            }
    int peek()
        {   
            //Again, check the nullity of the stack
            if (top < 0) {
                cout << "Stack is Empty";
                return 0;
            }
            //assign the values of the stack to new temporary variables and return that value.
            else {
                int x = a[top];//value of top is not changed here.
                return x;
            }
        }
    bool isEmpty()
        {
            return (top < 0); //top must be -1 to show that the stack is empty
        }
};

void printStack(Stack s)
{
    while(!s.isEmpty())
    {
        //print top element of the stack
        cout<<s.peek()<<endl;
        //remove top elements in the stack
        s.pop();

    }
}
int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<s.pop()<<" the top-most element of the stack is popped\n ";
    cout<<"Elements present in the stack are \n";
    printStack(s);

    
    return 0;
}