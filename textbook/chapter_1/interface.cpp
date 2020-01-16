#include "interface.h"

IntCell::IntCell(int InitialValue)
        : StoredValue {InitialValue}
{

}

int IntCell::IntRead() const
{
        return StoredValue;
}

void IntCell::IntWrite(int x)
{
        StoredValue = x;
}
