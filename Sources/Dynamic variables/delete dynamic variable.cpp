#include <iostream>
using namespace std;
int main()
{
    // delete operator
    double* ptr = new double(5);
    // process 
    // then delete it
    delete ptr; 
    // delete cause dangling pointer to avoid this : 
    ptr = NULL; // or ptr = nullptr ;
}