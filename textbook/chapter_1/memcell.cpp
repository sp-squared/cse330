#include <iostream>
using namespace std;

template <typename T>
class MemoryCell
{
public:
        explicit MemoryCell (const T & initialValue = T{})
                :storedValue{initialValue}
                {}
                const T & read() const
                        {return storedValue;}
                void write (const T & x)
                        {storedValue = x;}
                private:
                        T storedValue;

};

int main()
{
        MemoryCell <int> m1;
        MemoryCell <string> m2 {"hello"};
        m1.write(37);
        m2.write(m2.read() + " world!");
        cout << m1.read() << endl;
        cout << m2.read() << endl;

}
