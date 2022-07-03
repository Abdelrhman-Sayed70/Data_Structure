#pragma once
template <class N>
class rectangle
{
private: 
	N width;
	N height;
public:
	rectangle(N, N);
	rectangle();
	N area();
	~rectangle(void);
};

