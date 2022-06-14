#include<iostream>
#include<vector>
using namespace std; 
int main()
{

//CREATING A VECTOR
    vector<int> v; //statically created vector of type int
    //vector<int>* vp = new vector<int>(); //dynamically created vector or type int. Hence we created a vector pointer.
//CHECKING SIZE OF A VECTOR
    cout<<"The size of the vector is "<<v.size()<<endl; //size is 0
//INSERTING AN ELEMENT INTO A VECTOR
    //to enter the elements in the vector we use an in-built function called push_back()
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    cout<<"The size of the vector is "<<v.size()<<endl; //size is 3

    //works like an array 10 20 30. And we can treat it like that.

    cout<<v[0]<<endl<<v[1]<<endl<<v[2]<<endl;

    v[1]=100;
    cout<<v[0]<<endl<<v[1]<<endl<<v[2]<<endl;

    v.push_back(56);
    v.push_back(234);
    cout<<"The size of the vector is "<<v.size()<<endl; //size is 5 . Hence, vector automatically keeps updating its size.
    //DELETING AN ELEMENT FROM A VECTOR
    v.pop_back(); //pops out the last element of the vector
    cout<<"The size of the vector is "<<v.size()<<endl; //size is 5 . Hence, vector automatically keeps updating its size.
    //to access the elements we can similarly use at()
    /*
    to print the elements we can even use a for loop. And in this case we can use use [] or at(); our choice

    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<endl; OR cout<<v.at(i);
    }
    
    */
    for(int i=0;i<v.size();i++)
    {
        cout<<v.at(i)<<endl;
    }
    
    cout<<v.at(0)<<endl<<v.at(1)<<endl<<v.at(2)<<endl<<v.at(3)<<endl<<v.at(4)<<endl<<v.at(5)<<endl;
    //at the 4th and 5th index since we have no element, we get an error. Hence at() is much much safer to use
    //but after this error, no other code will be executed as an exit() is initiated


    return 0;
}