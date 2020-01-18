#include <iostream>
#include <vector>
#include <string>
using namespace std;

void randomItem(const vector <string> &arr)
{
        cout << "pass by constant-reference";
}

void randomItem(vector <string> &&arr)
{
        cout << "pass by r-value reference";
}

int main()
{
        vector <string> v {"hello", "world"};
        randomItem(v);
        cout << endl;
        randomItem({"hello","world"});
        cout << endl;

return 0;
}
