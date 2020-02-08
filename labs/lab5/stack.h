#ifndef STACK_H_
#define STACK_H_

#include "Vector.h"
using namespace std;

template <typename C>
class Stack
{
public:
	typedef typename C::value_type value_type;

	Stack()
	{}

	int size() const
	{
		return the_stack.size();
	}

	bool empty() const
	{
		return the_stack.empty();
	}

	void push(const value_type& x)
	{
		the_stack.push_back(x);
	}

	void pop()
	{
		the_stack.pop_back();
	}

	value_type top() 
	{
		return the_stack.back();
	}

private:
	C the_stack;
};

#endif
