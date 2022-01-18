//PASSING ONE DIMENSIONAL ARRAY TO A FUNCTION
#include<iostream>
using namespace std;
void display(int m[5])
{
    cout<<"The displayed marks are \n";
        for (int i=0; i<5;i++)
        {
            cout<<m[i]<<endl;

        }
}
int main()
{
    /*SYNTAX
    returnType functionName(dataType arrayName[arraySize]) {
    // code
    */
   int marks[]= {45,34,68,98,21};

   display(marks);


    return 0;
}