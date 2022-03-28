#include<iostream>
using namespace std;

void merge(int arr[],int l,int mid,int r)
{
    //we make 2 temporary arrays
    int n1 = mid-l+1;
    int n2 = r-mid;

    int a[n1];
    int b[n2];
    //the purpose of these 2 arrays is because we have to comapre the arrays and then merge. This wouldn't have been possible inn a single array

    //filling th evalues inn individual arrays
    for(int i=0;i<n1;i++)
    {
        a[i]=arr[l+i]; 
    }
    for(int i=0;i<n2;i++)
    {
        b[i]=arr[mid+1+i];
    }
    int i=0;
    int j=0;
    int k=l;//this one traverses the main array and starts from 'l'
    //till when will the comparing of elements go on?
    while(i<n1 && j<n2)
    {
        if(a[i]<b[j])
        {
            arr[k]=a[i];
            k++;i++;
        }
        else{
            arr[k]=b[j];
            k++;j++;
        }
        //but there also a case when there will be odd terms in an array. Meaning the first half will finish first and the last half wont
        //the below 2 functions ensure that this does not happen
        
    }
        while(i<n1)
        {
            arr[k]=a[i];
            k++; i++;
        }
        while(j<n2)
        {
            arr[k]=b[j];
            k++; j++;
        }
    
}

void mergeSort(int arr[],int l, int r)
{
    // l is 1 pointer and r is another pointer
    if(l<r)
    {
        //had l been equal to r it means there is only one element in our array
        int mid = (l+r)/2;
        //As we can see, most of the work is done directly on the array itself

        mergeSort(arr,l,mid); // this will sort the first part of the array 
        mergeSort(arr,mid+1,r);// this will sort the second part of the array
        merge(arr,l,mid,r);
    }
    //when l=0 and r=0 the function returns to its call. if we did not put the below else it would still return.
    else{
        return;
    }
}

int main()
{
     int arr[]={5,4,3,2,1};
    for(int i =0;i<5;i++)
     {
         cout<<arr[i]<<" ";
     }
     cout<<endl;
     mergeSort(arr,0,4);
     for(int i =0;i<5;i++)
     {
         cout<<arr[i]<<" ";
     }
     cout<<endl;
     return 0;
}