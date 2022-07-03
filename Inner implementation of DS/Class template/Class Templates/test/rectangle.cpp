#include "StdAfx.h"
#include "rectangle.h"




template <class N>
rectangle<N>::rectangle():width(0),height(0) {}

template <class N>
rectangle<N>::rectangle(N w, N h):width(w),height(h) {}

template <class N>
N rectangle<N>::area()
{
	return width*height;
}


template <class N>
rectangle<N>::~rectangle(void)
{
}
