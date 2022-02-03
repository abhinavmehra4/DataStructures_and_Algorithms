//Following is pass by reference function without pointers
/*#include<iostream>
using namespace std;

void swap(int &n1,int &n2)
{
    int temp;
    temp = n1;
    n1=n2;
    n2=temp;
}

int main()
{
    int x,y;

    x=5;y=6;

    cout<<x<<endl<<y<<endl;

    swap(x,y);
    cout<<x<<endl<<y<<endl;
// In the swap() function, the function parameters n1 and n2 are pointing to the same value as the variables a and b respectively. 
//Hence the swapping takes place on actual value.
    return 0;
}
*/

//Call by reference implementation using pointers

#include<iostream>
using namespace std;
void swap(int* n1, int* n2)// in the function we receive values
{
    int temp;

    temp = *n1;
    *n1 = *n2;
    *n2=temp;
}
int main()

{
    int a=5, b=6;

    cout<<a<<endl<<b<<endl;

    swap(&a,&b); 
    //Here, the address of the variable is passed during the function call rather than the variable being passed.
    //Since the address is passed instead of value, a dereference operator * must be used to access the value stored in that address.

    /*
        *n1 and *n2 gives the value stored at address n1 and n2 respectively.
        Since n1 and n2 contain the addresses of a and b, anything is done to *n1 and *n2 will 
        change the actual values of a and b.
        Hence, when we print the values of a and b in the main() function, the values are changed.
    */
    cout<<a<<endl<<b<<endl;


    return 0;
}