#include<iostream>
using namespace std;

int binarySearch(int input[],int start,int end,int x)
{
    int mid = (start+end)/2;
    if(start>end)
        return -1;
    if(x==input[mid])
        return mid;
    else if(x>input[mid])
        binarySearch(input,mid+1,end,x);
    else    
        binarySearch(input,start,mid-1,x);
}

int main()
{
    cout<<"Enter the number of term of the array\n";
    int n;
    cin>>n;
    int* input = new int[n];
    for(int i =0;i<n;i++)
    {
        cin>>input[i];
    }

    cout<<"Enter the element you want to search\n";
    int x;
    cin>>x;
    int position = binarySearch(input,0,n-1,x);
    cout<<position<<endl;
    (position!=-1)?cout<<"The index of the element is "<<position<<endl:cout<<"The element is not present in the array\n";

    delete [] input;
    return 0;
}