// Program to demonstrate an
// l-value pass by reference

#include <iostream>
#include <string>
using namespace std;
int main()
{
        string str = "hell";
        string & rstr = str;
        cout << rstr << endl;
        cout << str << endl;

        bool cond = (&str == &rstr);
        if (cond == 0)
        {
                cout << "They are not equal" << endl;
        }else
        {
                cout << "They are equal" << endl;
        }

        // memory address of str is
        // equal to that of rstr

        // str is a pointer to rstr
        // str -> rstr
        // str is a reference to rstr
return 0;
}
