#include "template.h"
#include <iostream>
#include <vector>
using namespace std;
int main()
{
        vector <int>     v1{37,706,67};
        vector <double>  v2{40,60,999};
        vector <string>  v3{"80", "90", "00", "900000"};
        //vector <IntCell> v4(75);

        cout << findMax(v1) << endl;
        cout << findMax(v2) << endl;
        cout << findMax(v3) << endl;
        //cout << findMax(v4) << endl;


return 0;
}
