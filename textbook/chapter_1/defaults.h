#ifndef DEFAULTS_H
#define DEFAULTS_CLASS_H
#include <iostream>
using namespace std;
class IntCell
{
public:
        explicit IntCell(int initialValue = 0)
                {storedValue = new int{initialValue};}

        int IntRead() const
                {return *storedValue;}
        void IntWrite (int x)
                {*storedValue = x;}
private:
        int *storedValue;
};
#endif
