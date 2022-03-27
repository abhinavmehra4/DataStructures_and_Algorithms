//substring is continuous while subsequences are random
//abcd
//abc, bcd,bc are substrings
//ad,cbda, etc are subsequences. MORE LIKE ALL POSSIBLE COMBINATIONS. And there will be 2^n combinations

//but in this we have to return many subsequences which are nothing but strings right? So we need a string array. 
//or better a pointer


#include<iostream>
#include<string.h>
using namespace std;

int subs(string input,string output[])
{
    //all output subsequences will be stored in  the form of an array.

    //base case
    if(input.empty())//checks if the string is empty or we could've done if(input.size()==0)
    {
        output[0]=" ";
        return 1;//the size of the output array is 1 and the contents are filled.
    }

    //recursive call
    //we cannot do this the same way we did with arrays, that is by shifting the index pointer by 1.

    string smallerString = input.substr(1);
    int smallOutputSize= subs(smallerString,output); //in smallOutputSize the size of the array is stored.

            //the above 2 instructions are equivalent to "input+1"

    //if our input is "abc". then after this step assume we have [" ", b,c,bc]

    /*
        what we have to do now is take this, [" ", b,c,bc], and after 'bc' copy these exact terms 
        below and attach an 'a' to them.
    */


    for(int i =0;i<smallOutputSize;i++)
    {
        output[i+smallOutputSize]=input[0]+output[i]; //changes are made to the original output array.
        //here the first 4 terms are [" ", b,c,bc], then after 'bc' we are adding the terms again by concatenating
        //them with an 'a'. And input[0] corresponds to the 'a'.
    }

    //as the size of the output has been doubled 
    return 2*smallOutputSize; 



}

int main()
{
    string input;
    cin>>input;
    //technicall one should do
        // int size = input.size();
        // string* output = new string[size];
    
    //But right now we do this
    string* output = new string[1000];//dynamically create a string output array of size 1000
    int count = subs(input,output);
    for(int i =0;i<count;i++)
    {
        cout<<output[i]<<endl;//this prints all subsequences
    }
    return 0;
}