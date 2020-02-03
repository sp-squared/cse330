#include <iostream>
using namespace std;

void swap (int & a, int & b)
{
        b = b+1;
        a = a+1;
        //cout << a << " " << b << endl;

}


int main()
{
        int x = 5;
        int y = 9;
        swap(x,y);
        cout << x << " " << y << endl;

}
