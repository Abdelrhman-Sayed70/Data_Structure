#include "stackArr.h"
#include<assert.h>
stackArr::stackArr(void) {
	current_size = 10;
	num_of_values = 0;
	arr = new int[current_size];
}
int stackArr::Length()
{
	return num_of_values;
}
void stackArr::push(int val){
	if (current_size > num_of_values) { arr[num_of_values] = val; }
	else { Expand();arr[num_of_values] = val; }
	num_of_values++; 
}
bool stackArr::empty() {
	return(num_of_values == 0); 
}
void stackArr::Expand() {
	current_size *= 2; 
	int* tmp = new int[current_size];
	for (int i = 0; i < num_of_values; i++) {
		tmp[i] = arr[i];
	}
	delete[] arr;
	arr = tmp; 
}
void stackArr::pop() {
	assert(num_of_values!=0);
	num_of_values--;
}
int stackArr::top() {
	assert(num_of_values!=0);
	return arr[num_of_values - 1];
}
stackArr::~stackArr(void){
	delete[]arr;
}
