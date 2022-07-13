#include<iostream>
#include<string>
using namespace std;
#include<unordered_map> //this is template. So we gotta specify stuff

int main()
{
    unordered_map<string, int> ourmap;

    //insert - we have to insert a key and a value
    pair<string,int> p("abc",1); //this is the inbuilt pair class to pass the key value pair
    ourmap.insert(p);
        //we can even insert in this manner
        ourmap["def"] = 2; //def is the key and the value corresponding to it is 2
    
    //accessing the elements
    cout<<ourmap["abc"]<<endl;
    cout<<ourmap.at("abc")<<endl; //but  this create an exception if key doe snot exist
    //but if we do ourmap["key_that_doesnt_exist"], then it will insert this key with default value 0 and return that

    //check the presence of a key
    if(ourmap.count("def")>0) //ourmap.count() will return the count of "def" elements
        cout<<"def is present"<<endl;
    else
        cout<<"It doesn't";

    //erase - ourmap.erase("ghi") 
    ourmap.erase("ghi");

    //to get the size
    cout<<ourmap.size()<<endl;

    return 0;
}