//the following code is for the expressions without whitespaces
#include<iostream>
#include<string.h>
using namespace std;

#define MAX 100

//these are globally declared as everyunction can use them
char stack[MAX]; //to store the whole postfix expression
char infix[MAX]; //infix to store the expression
char postfix[MAX];
int top=-1;//indicates the index of the topmost element of the stack;

void push(int symbol)
{
    if(top>=MAX-1)
    {
        cout<<"Stack overflow\n";
        return;
    }
    stack[top++]=symbol;
}

int pop()
{
    if(top<0)
    {
        cout<<"Stack underflow\n";
        return 0;
    }
    else
    return stack[top--];
    
}

int isEmpty()
{
    if (top<0)
    {
        return 1;
    }
    else
    return 0;
    
}

int precedence(char symbol)
{
    switch(symbol)
    {
        case '^':
            return 3;
        case '/':
        case '*':
            return 2; //this shows that for both the cases, this value will be returned
        case '+':
        case '-':
        return 1;
        default:
        return 0;
    }
}
void inToPost()
{
    char symbol,next;
    int i,j=0;
    for(i=0;i<strlen(infix);i++)
    {
        symbol = infix[i];
        //in the algo, there are many if else cases, hence it is better to just use a switch case syntax
        switch (symbol)
        {
        case '(':
            push(symbol);
            break;
        case ')':
            while ((next=pop())!='(')
            {
                postfix[j]=next;
                j++;
                //but instead of printing, we store the elements in the postfix array
            }
            //our job was also to see that both the parenthesis get ppopped out of the stack and 
            //this loop does ensure that
            break; 
            case '-':
            case '+':
            case '*':
            case '/':
            case '^':
                while(!isEmpty()&&(precedence(stack[top])>=precedence(symbol)))
                {
                    postfix[j]=pop();
                    j++;
                }
                push(symbol);
                break;
        default:
        //if the symbol is an operand, we simply put the operand in the postfix array
        {
            postfix[j]=symbol;
            j++;
        }
        
        }
    }
    //we must check if the while stack is empty or not. It is an important thing to do
    while(!isEmpty())
    {
        postfix[j]=pop();
        j++;
        postfix[j]='\0';
    }
}
void print(int n)
{
    for(int i =0;i<n;i++)
    {
        cout<<postfix[i];
    }
}
int main()
{
    //get the expression from the user
    cout<<"Enter the infix expression: \n";
    gets(infix); //this is from the string module. And because it's a string there will be a "end of string" function

    //call the function to convert infix to postfix
    inToPost();
    int n =sizeof(postfix)/sizeof(postfix[0]);
    print(n);
    
    return 0;
}