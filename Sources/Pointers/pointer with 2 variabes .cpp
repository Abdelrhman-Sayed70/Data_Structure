#include<iostream>
using namespace std; 
int main() {
    // pointer can change his point 
    int v, w; 
    int* p;
    p = &v;
    v = 3;
    // change the value of v 
    *p = 7;
    cout << v <<"\n";  // display 7
    p = &w;
    *p = 18;
    cout <<  w << "\n"; // display 18 ;
}