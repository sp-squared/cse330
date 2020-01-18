#include <iostream>
#include <string>
using namespace std;
int main()
{
        string str = "hell";
        string && bad1 = "hello";
        string && bad2 = str + "";
        string && sub = str.substr(0,4);

        cout  << bad1 << endl;
        cout  << bad2 << endl;
        cout  << sub << endl;

return 0;
}
