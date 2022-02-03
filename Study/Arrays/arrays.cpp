/*#include<iostream>
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
*/

/*//Program to output contents of a 3x2 matrix
#include <iostream>
using namespace std;

int main() {
    int test[3][2] = {{2, -5},
                      {4, 0},
                      {9, 1}};
    for (int i = 0; i < 3; ++i) { //corresponds to the number of rows

        for (int j = 0; j < 2; ++j) {//Corresponds to the columns in each row
            cout << "test[" << i << "][" << j << "] = " << test[i][j] << endl;
        }
    }

    return 0;
}
*/

//PROGRAM TO INPUT DATA INT O A 2 DIMENSIONAL ARRAY
#include <iostream>
using namespace std;

int main() {
    int numbers[2][3];

    cout << "Enter 6 numbers: " << endl;

    // Storing user input in the array
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> numbers[i][j];
        }
    }

    cout << "The numbers are: " << endl;

    //  Printing array elements
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << "numbers[" << i << "][" << j << "]: " << numbers[i][j] << endl;
        }
    }

    return 0;
}