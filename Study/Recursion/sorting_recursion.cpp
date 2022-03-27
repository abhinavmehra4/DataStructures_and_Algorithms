#include<iostream>
using namespace std;

bool isSorted(int a[],int size)
{
    if(size==1||size==0)
    return true;

    if(a[0]>a[1])
    return false;

    //it is important to know that when we pass arrays, we are passing the address of the array,
    //something like pointer, but not exactly that hence to apply the function from the next position
    //we just simply shift the pointer to the next adjacent index and call the function.
    bool isSmallerSorted = isSorted(a+1,size-1);
    return isSmallerSorted;

}

int main()
{


    return 0;
}