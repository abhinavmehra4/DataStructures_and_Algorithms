#include<iostream>
using namespace std;
#include "Pair.cpp"

int main()
{
    Pair<int> p1;
    p1.setX(10);
    p1.setY(20);

    cout<<p1.getX()<<" "<<p1.getY()<<endl;

    Pair<double> p2;

    p2.setX(100.34);
    p2.setY(34.31);

    cout<<p2.getX()<<" "<<p2.getY()<<endl;
    
    //if there are different types for different variables of the class
    //EXAMPLE: Pair<int,double> p3 : We declare it like this.
    return 0;
}