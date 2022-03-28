#include<iostream>
using namespace std;

int linearSearch(int arr[],int n,int x)
{
    for(int i =0;i<n;i++)
    {
        if(x==arr[i])
            return i;
    }
    return -1;

}
int main()
{
    int arr[]={2,4,0,1,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x =1;
    int index = linearSearch(arr,n,x);
    (index!=-1)?cout<<"The index of the element is "<<index<<endl:cout<<"The element is not present in the array\n";
    
    int y =5;
    index = linearSearch(arr,n,y);
    (index!=-1)?cout<<"The index of the element is "<<index<<endl:cout<<"The element is not present in the array\n";

    
    return 0;
}