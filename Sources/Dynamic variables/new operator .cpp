#include <iostream>
using namespace std;
int main()
{
    // new operator
    int* ptr;
    // creat new place in memory and put in it 5 
    ptr = new int(5);
    cout << *ptr;
}