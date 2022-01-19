#include<iostream>
using namespace std;
class Student{
int age;
public:
Student(): age(12) {}
void getAge(){
    cout<<"The age is "<<age<<endl;
}

};
int main()
{
    Student* ptr = new Student();
    ptr->getAge();

    // the arrow operator ->. This operator is used to access class members using pointers.

    delete ptr; //deallocation of memory
    
    return 0;
}