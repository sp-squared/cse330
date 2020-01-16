#include <iostream>
#include "interface.h"
using namespace std;
int main(){
        IntCell num1;
        num1.IntWrite(6);
        cout << "Num 1 = " << num1.IntRead() << endl;

        IntCell num2 (12);
        cout << "Num 2 = " << num2.IntRead() << endl;
return 0;
}
