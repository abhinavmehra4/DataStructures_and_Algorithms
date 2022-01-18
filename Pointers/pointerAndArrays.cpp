#include<iostream>
using namespace std;
int main()
{
    int *ptr;
    int arr[5]={2,4,6,8,10};
    ptr = arr;
    // store the address of the first element of arr in ptr
    // we have used 'arr' instead of '&arr[0]'. This is because both are the same. 

    /*
        HENCE THE CODE GIVEN BELOW IS SAME AS ABOVE

        int *ptr;
        int arr[5];
        ptr = &arr[0];
    
    */
   for(int i=0;i<5;i++)
   {
       cout<<"Address of "<<i<<"th element is "<< ptr + i<< " and the value is "<< *(ptr+i) <<endl ;

   }

   /*
            IMPORTANT

            ptr + 1 is equivalent to &arr[1];
            ptr + 2 is equivalent to &arr[2];
            ptr + 3 is equivalent to &arr[3];
            ptr + 4 is equivalent to &arr[4];

            *ptr == arr[0]; OR (ptr + 0) is equivalent to arr[0];
            *(ptr + 1) is equivalent to arr[1];
            *(ptr + 2) is equivalent to arr[2];
            *(ptr + 3) is equivalent to arr[3];
            *(ptr + 4) is equivalent to arr[4];

    Suppose if we have initialized ptr = &arr[2]; then

            ptr - 2 is equivalent to &arr[0];
            ptr - 1 is equivalent to &arr[1]; 
            ptr + 1 is equivalent to &arr[3];
            ptr + 2 is equivalent to &arr[4];

The address between ptr and ptr + 1 differs by 4 bytes. It is because ptr is a pointer to an int data. And, the size of int is 4 bytes in a 64-bit operating system.
Similarly, if pointer ptr is pointing to char type data, then the address between ptr and ptr + 1 is 1 byte. It is because the size of a character is 1 byte.

   
   */
   
    return 0;
}