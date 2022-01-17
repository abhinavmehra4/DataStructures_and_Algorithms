#include<iostream>
using namespace std;
int main()
{
    // METHOD 1- dataType arrayName[arraySize];
    // int x[6] = {19, 10, 8}; In these cases, the remaining values of the array have random values assigned to them.
    //  syntax to access array elements : array[index];
    // METHOD 2- declare and initialize and array : int x[6] = {19, 10, 8, 17, 9, 15};
    // METHOD 3- // declare and initialize an array : int x[] = {19, 10, 8, 17, 9, 15}; THIS IS A BETTER METHOD

// INSERTING AND PRINTING MEMBERS OF AN ARRAY

int x[] = {2,3,4,5,6,7};

x[5]= 67;

cin>> x[4];
cout<< x[4] << endl << x[2];;


    return 0;
}