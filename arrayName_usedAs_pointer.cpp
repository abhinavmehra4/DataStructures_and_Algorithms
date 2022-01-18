#include<iostream>
using namespace std;
int main()
{
    /*
    In most contexts, array names decay to pointers. In simple words, array names are converted to pointers. That's the reason why we can use pointers to access elements of arrays.
    However, we should remember that pointers and arrays are not the same.
    There are a few cases where array names don't decay to pointers. 
    */

   float arr[5];
    cout << "Enter 5 numbers: ";
    for (int i = 0; i < 5; ++i) 
    {
        cin >> *(arr + i) ;
    }
    cout << "Displaying data: " << endl;
    for (int i = 0; i < 5; ++i) 
    {
        cout << *(arr + i) << endl ; //array name is used as a pointer. so just replace pointer variable with array name and the rest remains same.
    }
    return 0;
}