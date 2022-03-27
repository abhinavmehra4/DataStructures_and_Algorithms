#include<iostream>
#include<string.h>

using namespace std;

//let's take this example with string 'abc'
void print_subs(string input, string output)
{
    //base case
    if(input.length()==0) //if(input.empty())
    {
        cout<<output<<endl; //when we have reached the empty string all we have to do is print the output and return.
        return;
    }

    //now say we dont want to include the input[0] element, so we pass it as it is.

    print_subs(input.substr(1),output);// analogous to input+1 and since the output size is same, we pass it as it is.
    print_subs(input.substr(1),output+input[0]);
    //now this is the ohter case where the term input[0] is included
}

int main()
{
    string input;
    cin>>input;
    string output =" ";//initialised
    print_subs(input,output);
    return 0;
}

//it is hitting a lot of base cases and uses less space. this approach is used to hit a lot of base cases, many a a time.

//since we are moving in 2 different directions this method definitely helps.