#include<iostream>
#include<vector>
using namespace std;
class PriorityQueue{
vector<int> pq; //to store CBT

public:


bool isEmpty()
{
    return pq.size()==0;
}

//return number of elements in priority queu
int getSize()
{
    return pq.size();
}

//get the minimum element
//since our vector has elemets and in case of elements the priority is same as integer value
int getMin(){
    //and minimum element will always be stored at the root in case of heaps
if(isEmpty())
    return 0;
return pq[0];
}

void insert(int element)
{
    pq.push_back(element); //puts at the end of the vector
    //to figure out the childIndex
    int childIndex = pq.size()-1;
    //now we have to compare them and accordingly swap, considering it is a min Heap
    //i.e Heapify
    
    /*
    But we cannot stop here, as we have to check the Heap Order property again
    Hence the element at parentIndex becomes the child. Therefore
    chlidIndex=parentIndex

But till when should this process be carried out pon two conditions:-
    1)til we reaach the root
    2)till we reach the correct position

    */

   while(childIndex>0)
   {
        int parentIndex = (childIndex-1)/2;
        if(pq[childIndex]<pq[parentIndex]) //condition 1
            {
                int temp = pq[childIndex];
                pq[childIndex]=pq[parentIndex];
                pq[parentIndex]=temp;
            }
            else{ //condition 2
                break;
            }
        childIndex=parentIndex;
    }
        
}

int removeMin()
{
    if(isEmpty())
    {
        return 0;
    }
    int ans = pq[0];
    pq[0] = pq[pq.size()-1];
    pq.pop_back();
    
    //down heapify
    int parentIndex =0;
    int leftChildIndex = 2*parentIndex+1;
    int rightChildIndex = 2*parentIndex+2;
    
    while(leftChildIndex<pq.size())
    {
        int minIndex = parentIndex;
        if(pq[minIndex]>pq[leftChildIndex])
            minIndex=leftChildIndex;
        if(rightChildIndex<pq.size() && pq[rightChildIndex]<pq[minIndex])
            minIndex=rightChildIndex;
        if(minIndex==parentIndex)
            break;
        //swap
        int temp = pq[minIndex];
        pq[minIndex] = pq[parentIndex];
        pq[parentIndex] = temp;

        parentIndex = minIndex;
        leftChildIndex = 2*parentIndex+1;
        rightChildIndex = 2*parentIndex+2;
    }
    return ans;
}

};