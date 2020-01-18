#include "interface.h"
#include <iostream>
using namespace std;
int main()
{
        IntCell *m;

        m = new IntCell{0};
        m->IntWrite(5);
        cout << "Cell Contents : " << m->IntRead() << endl;
        delete m;

return 0;
}
