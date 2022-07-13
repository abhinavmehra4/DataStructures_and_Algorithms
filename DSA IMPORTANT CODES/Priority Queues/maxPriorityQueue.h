#include<iostream>
using namespace std;
#include <vector>

class PriorityQueue {
    // Declare the data members here
    vector<int> pq;

   public:
    PriorityQueue() {
        // Implement the constructor here
    }


    void insert(int element) {
        pq.push_back(element); //pushed back. Now we gotta link it to its parent
        int childIndex= pq.size()-1;
        //now we have to compare them and accordingly swap, considering it is a max Heap
    //i.e Heapify
    
            /*
            But we cannot stop here, as we have to check the Heap Order property again
            Hence the element at parentIndex becomes the child. Therefore
            chlidIndex=parentIndex.

        But till when should this process be carried out pon two conditions:-
            1)til we reaach the root
            2)till we reach the correct position
            */


        while(childIndex>0)
        {
            int parentIndex = (childIndex-1)/2;
            if(pq[childIndex]>pq[parentIndex])//condition1
                {
                    int temp = pq[childIndex];
                    pq[childIndex]=pq[parentIndex];
                    pq[parentIndex]=temp;
                }
            else
                break;
            
            childIndex=parentIndex;
        }
    }

    int getMax() {
        if(isEmpty())
            return 0;
        return pq[0];
    }

    int removeMax() {
        if(isEmpty())
            return 0;

        int ans=pq[0];
        pq[0]=pq[pq.size()-1];
        pq.pop_back();

        //down heapify
        int parentIndex=0;
        int leftChildIndex = 2*parentIndex+1;
        int rightChildIndex = 2*parentIndex+2;
        while(leftChildIndex<pq.size())
        {
            int maxIndex=parentIndex;
            if(pq[maxIndex]<pq[leftChildIndex])
                maxIndex=leftChildIndex;
            if(rightChildIndex<pq.size() && pq[rightChildIndex]>pq[maxIndex])
                maxIndex=rightChildIndex;
            if(maxIndex==parentIndex)
                break;
            
            int temp = pq[maxIndex];
            pq[maxIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = maxIndex;
            leftChildIndex = 2*parentIndex+1;
            rightChildIndex = 2*parentIndex+2;  
        }
        return ans;
    }

    int getSize() { 
        return pq.size();
    }

    bool isEmpty() {
        return pq.size()==0;
    }
};