#include<iostream>
#include<string>
using namespace std;

void removeX( char s[])
{
    //base case
    if(s[0]=='\0')
    return;

    //recursive call
    if(s[0]!='x')
    return removeX(s+1);

    else{
        int i=1;
        for(;s[i]!='\0';i++)
        {
            s[i-1]=s[i];
        }
        //but after the loop ends the null character is not shifted due to restrictions imposed by c++
        s[i-1]=s[i];// sinc i is att the null character position. We had to also shift the null character. 
        //So we did just that with this step

        //IMPORTANT
        removeX(s);
        //due to shifting the string size had already reduced. So we dont have to call recursively as removeX(s+1).

    }

}

int length(char s[])
{
    if(s[0]=='\0')
    return 0;//as the length of the string is zero

    int stringLeft = length(s+1);
    return stringLeft +1;
}

int main()
{
    char str[100];
    cin>>str;
    int l = length(str);
    cout<<l<<endl;

    //function to remove x
    removeX(str);
    cout<<endl<<str; //direct changes in the string will be reflected
    cout<<endl<<length(str);//to check the length
    return 0;
}