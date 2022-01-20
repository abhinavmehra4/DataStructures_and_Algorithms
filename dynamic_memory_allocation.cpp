#include<iostream>
using namespace std;
int main()
{
    int* pointerVar;

    pointerVar = new int; //dynamically, memory has been alloted to the pointer variable, pointerVar;
    *pointerVar = 45; //the value 45 is stored at the address 

    /*
    Notice that we have used the pointer pointVar to allocate the memory dynamically. This is because the new operator returns the address of the memory location.
    In the case of an array, the new operator returns the address of the first element of the array.
    */

    cout<<*pointerVar<<endl;

    delete pointerVar; //After printing the contents of pointVar, we deallocated the memory using delete.

    return 0;
}