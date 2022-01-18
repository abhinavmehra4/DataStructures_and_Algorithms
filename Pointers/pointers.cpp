#include<iostream>
using namespace std;
int main()
{
    int var1 =3, var2=4, var3=5;
    cout<<&var1<<endl<<&var2<<endl<<&var3<<endl;

//DATATYPE OF THE PINNER AND THE VARIABLE TO WHICH IT POINTS TO MUST BE SAME

    int* pointVar, var;// here both pointVar and var are not pointers but only pointVar is a int data type pointer. var is a just an int data type variable.
    var=5;
    pointVar=&var;

    cout<<"Address of var"<<&var<<endl;
    cout<<"address of var"<<pointVar<<endl;
    cout<<"Value of var "<<var<<endl;
    cout<<"Value of var "<<*pointVar<<endl;

//WHEN WE CHANGE THE VALUE OF THE VARIABLE USING THE POINTER THEN A COPY OF THE VARIABLE IS NOT MADE.
//BUT INSTEAD THE ACTUAL VALUE STORED IN THE VARIABLE GETS CHANGED.

    *pointVar = 56;

    cout<<"Address of new var"<<&var<<endl;
    cout<<"address of new var"<<pointVar<<endl; //the address stored in thepointer variable does not change because the variable to which it points to has not changed
    cout<<"Value of new var "<<var<<endl;
    cout<<"Value of new var "<<*pointVar<<endl;

    /*COMMON MISTAKES TO KEEP TRACK OF*/
    /*      int var, *varPoint;

            // Wrong! 
            // varPoint is an address but var is not
            varPoint = var;

            // Wrong!
            // &var is an address
            // *varPoint is the value stored in &var
            *varPoint = &var;

            // Correct! 
            // varPoint is an address and so is &var
            varPoint = &var;

            // Correct!
            // both *varPoint and var are values
            *varPoint = var;
    */
                

    return 0;
}