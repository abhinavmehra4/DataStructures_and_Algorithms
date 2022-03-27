#include<iostream>
using namespace std;

int count(int n)
{
    if (n/10==0)
    {
        return 1;
    }
    
    int digits=0;
    digits++;
    return count(n-1)/10
    
}

int main()
{

    int n;
    cin >> n;
  
    cout << count(n) << endl;
    return 0;
}