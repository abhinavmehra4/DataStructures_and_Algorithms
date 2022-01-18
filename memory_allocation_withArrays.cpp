#include<iostream>
using namespace std;
int main()
{ int num;
    cout<<"Enter the total number of students\n";
    cin>>num;

    float* ptr;
    ptr = new float[num];//dynamic memory allocation is done for the first element of the array
    cout<<"Enter the GPA of students "<<endl;
    for(int i=0;i<num;i++)
    {   
        cin>>*(ptr+i);
    }
    for(int i=0;i<num;i++)
    {
        cout<<"The GPA of Student "<<i+1<<" is "<<*(ptr+i)<<endl;
    }

    delete [] ptr; //deallocation of the memory
    
    return 0;
}