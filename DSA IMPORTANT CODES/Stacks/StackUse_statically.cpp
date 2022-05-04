#include<iostream>
#include "stack_arrays.cpp"
#include "stacks_using_dynamic_arrays.cpp"

using namespace std;

int main()
{

    stackUsingArrays s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout<<s.top()<<endl;

    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;

    cout<<s.size()<<endl;

    cout<<s.isEmpty()<<endl;

    
    return 0;
}