// Colin Morris-Moncada
// Lab 2
/* 

Trying to catch up with syntax and such since I did not learn
alot of the syntax used in the book and the labs

Taking Notes for chapter 1 in the textbook and trying to 
understand Lab 2 but I will not finish by 12:00 
*/

#ifndef VECTOR_H
#define VECTOR_H

#include <vector>
#include <iostream>
#include <cassert>
#include <cstdlib>
//#include "Random.h"




template <typename T>
class Vector
{
public:
	// Explicit Vector Default Constructor
	explicit Vector(int initSize = 0)
		: theSize {initSize},
		theCapacity{initSize + SPARE_CAPACITY}
	{ data = new T[theCapacity]; }


	// Vector Constructor
	Vector(const Vector& rhs)
		: theSize { rhs.theSize },
		theCapacity { rhs.theCapacity },
		data{ nullptr}
	{
		data = new T[theCapacity];
		for (int k = 0; k < theSize; ++k)
			data[k] = rhs.data[k];
	}





	static const int SPARE_CAPACITY = 2;


private:
	int theSize;
	int theCapacity;
	T* data;
};


#endif
