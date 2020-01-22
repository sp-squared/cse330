// Colin Morris-Moncada
// Lab 2
#ifndef VECTOR_H
#define VECTOR_H

#include <vector>
#include <iostream>
#include <cassert>

template <typename T>
class Vector
{
public:
	// Explicit Vector Default Constructor
	explicit Vector(int initSize = 0)
		: theSize {initSize},
		theCapacity{initSize + SPARE_CAPACITY}
	{ data = new T[theCapacity]; }


	// Copy Constructor
	Vector(const Vector& rhs)
		: theSize { rhs.theSize },
		theCapacity { rhs.theCapacity },
		data{ nullptr }
	{
		data = new T[theCapacity];
		for (int k = 0; k < theSize; ++k)
			data[k] = rhs.data[k];
	}

	// Copy Assignment
	Vector& operator= (const Vector& rhs)
	{
		Vector copy = rhs;
		std::swap(*this, copy);
		return *this;
	}

	// Destructor
	~Vector()
	{
		delete[] data;
	}

	// Move Constructor
	Vector(Vector&& rhs)
		: theSize{rhs.theSize},
		  theCapacity{rhs.theCapacity},
		  data{rhs.data}
	{
		rhs.data = nullptr;
		rhs.theSize = 0;
		rhs.theCapacity = 0;

	}

	// Move Assignment
	Vector& operator= (Vector&& rhs)
	{
		std::swap(theSize, rhs.theSize);
		std::swap(theCapacity, rhs.theCapacity);
		std::swap(data, rhs.data);

		return *this;
	}

	// empty function
	bool empty()
	{
		return size() == 0;
	}

	// size function
	int size()
	{
		return theSize;

	}

	// capacity function
	int capacity()
	{
		return theCapacity;
	}

	// operator []
	T& operator[](int index)
	{
		assert(index >= 0 && index < theSize);
		return data [index];
	}

	// resize function
	void resize(int newSize)
	{
		if (newSize > theCapacity)
		{
			reserve(newSize * 2);
		}
	}

	//reserve function
	void reserve(int newCapacity)
	{
		if (newCapacity  < theSize)
		{
			return;
		}

		T* newArray = new T[newCapacity];

		for (int k = 0; k < theSize; ++k)
		{
			newArray[k] = newCapacity;
		}

		theCapacity = newCapacity;
		std::swap(data, newArray);
		delete[] newArray;
	}

	// push back function l-value
	void push_back(const T& x)
	{
		if(theSize == theCapacity)
		{
			reserve (2 * theCapacity + 1);
		}
		data[theSize++] = x;
	}

	// push back function r-value
	void push_back(T&& x)
	{
		if(theSize == theCapacity)
		{
			reserve (2 * theCapacity + 1);
		}
		data[theSize++] = std::move(x);
	}

	// pop back function
	void pop_back()
	{
		assert(theSize >= 1);
		--theSize;
	}

	// back function

	const T& back() const
	{
		assert(theSize >= 1);
		return data[theSize -1];
	}

	// Iterators

	typedef T* iterator;
	typedef const T *const_iterator;

	iterator begin()
	{
		return &data[0];
	}

	const_iterator begin() const
	{
		return &data[0];
	}

	iterator end()
	{
		return &data[size()];
	}

	const_iterator end() const
	{
		return &data[size()];
	}

	static const int SPARE_CAPACITY = 10;


private:
	int theSize;
	int theCapacity;
	T* data;
};
#endif
