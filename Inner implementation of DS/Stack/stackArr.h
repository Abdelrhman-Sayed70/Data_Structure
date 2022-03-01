#pragma once
class stackArr
{
private:
	int* arr;
	int current_size;
	int num_of_values; 
public:
	stackArr(void); // constructor
	int Length(); 
	void push(int val);
	void pop();
	int top(); 
	bool empty();
	void Expand();
	~stackArr(void);
};