// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "rectangle.cpp"

using namespace std;



int main()
{
	rectangle<float> r1(2.3,3.5);
	cout<<"area= "<<r1.area()<<endl;
	return 0;
}

