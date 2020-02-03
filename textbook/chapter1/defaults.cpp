#include "bigfive.h"
//#include "defaults.h"
#include <iostream>
using namespace std;
int main()
{
        IntCell a{2};
        IntCell b = a;
        IntCell c;

        c=b;
        a.IntWrite(4);
        cout << a.IntRead() << endl;
        cout << b.IntRead() << endl;
        cout << c.IntRead() << endl;

return 0;
}
