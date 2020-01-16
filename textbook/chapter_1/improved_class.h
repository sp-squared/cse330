#ifndef IMPROVED_CLASS_H
#define IMPROVED_CLASS_H
#include <iostream>
using namespace std;
class IntCell
{
public:
	IntCell()
		{StoredValue = 0;}
	IntCell(int InitialValue)
		{StoredValue = InitialValue;}
	int IntRead()
		{return StoredValue;}
	void IntWrite(int x)
		{StoredValue = x;}
private:
	int StoredValue;
};
#endif