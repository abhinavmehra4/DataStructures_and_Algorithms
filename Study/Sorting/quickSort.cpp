#include<iostream>
using namespace std;

int partition(int input[],int si,int ei)
{
    //int size=ei-si+1;
    int count=0;
    for(int i=si+1;i<=ei;i++)
    {
        if(input[si]>=input[i])
            count++;
            
    }
    int partitionIndex=si+count;
    int tempswap=input[si];
    input[si]=input[partitionIndex];
    input[partitionIndex]=tempswap;
    int i=si,j=ei;
    while(i!=partitionIndex&&j!=partitionIndex)
    {
        if(input[i]<=input[partitionIndex])
        {
            i++;
        }
        else if(input[j]>input[partitionIndex])
        {
            j--;
        }
        else
        {
            tempswap=input[i];
            input[i++]=input[j];
            input[j--]=tempswap;
            
        }
    }
    return partitionIndex;
}
void qs(int input[],int si,int ei)
{
    if(si>=ei)
        return;
    int size=ei-si+1;
    int partitionIndex=partition(input,si,ei);
    qs(input,si,partitionIndex-1);
    qs(input,partitionIndex+1,ei);
}
void quickSort(int input[], int size) {
  
    qs(input,0,size-1);
}

int main()
{
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;
    return 0;
}