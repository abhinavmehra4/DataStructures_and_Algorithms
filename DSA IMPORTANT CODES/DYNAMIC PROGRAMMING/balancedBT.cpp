#include <iostream>
#include<cmath>
using namespace std;

int balancedBTs(int h) {
    // Write your code here
    if(h<=1)//at height 1 and 0 the answer is 1
        return 1;
    int mod = (int) (pow(10,9))+7;
    int x = balancedBTs(h-1);
    int y = balancedBTs(h-2);

//all combinations we will get by multiplyling and not adding. Simple PNC
//but answer is coming very very large. For them we simly do
    int temp1 = (int)((( (long)(x) *x))%mod) ;
    int temp2 = (int)((2*(long)(x)*y)%mod); 
    return  ;
}

int main() {
    int h;
    cin >> h;
    cout << balancedBTs(h);
}