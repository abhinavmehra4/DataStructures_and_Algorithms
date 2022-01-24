//very basic type of bubble sort algorithm.
#include<iostream>
using namespace std;
int main()
{
    int a[] = {-2,45,0,11,-9};
    int n = sizeof(a)/sizeof(a[0]);// a way to find the size of the array.
    cout<<n<<endl;

    for(int i=0; i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"The sorted order of the array is "<<endl;

    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp;
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    for(int i=0; i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}