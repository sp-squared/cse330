#include <iostream>
#include <vector>
using namespace std;
int main()
{
        vector <int> arr {12,13,14,15,16};
        for (auto  x: arr)
        {
                ++x;
                cout << x << " " ;
        }
        cout << endl;

        for(int i = 0; i < arr.size(); i++)
        {
                cout << arr[i] << " ";
                //cout << arr.at(i) << " ";
        }
        cout << endl;
return 0;
}
