#ifndef IMPROVED_CLASS_H
#define IMPROVED_CLASS_H
#include <iostream>
using namespace std;
class IntCell
{
public:
	// Example of the explicit constructor
	// and default parameter
	explicit IntCell(int InitialValue = 0)
		: StoredValue{ InitialValue }{}
	// Example of Const  Accsessor
	// Member Function
	int IntRead() const
	{ return StoredValue; }
	void IntWrite(int x)
	{ StoredValue = x; }
private:
	int StoredValue;
};
#endif
