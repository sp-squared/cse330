#include <vector>
#include <iostream>
//#include "lab6.h"
using namespace std;

template <typename T>
bool binsearch( vector <T> vec, T target)
{
        int low = 0;
        int high = vec.size() - 1;
        while (low <= high)
        {
                int mid = (low + high) / 2;
                //cout << mid;
                //cout << high << endl;

                T midVal = vec[mid];
                //cout << midVal;

                if (midVal == target)
                {
                        cout << "target value found!";
                        return true;
                }
                else if (midVal < target)
                {
                        cout << "not found";
                }

                }
}































/*void binary_search(const vector <int> & rhs)
{
        //int theSize = rhs.size();
        //cout << theSize << endl;


        int low = rhs[0];
        int high = rhs.size() - 1;
        cout << low << endl;
        cout << high << endl;



        for (int i = 0; i < container.size(); i++)
        {
                if ( low <= high )
                {
                        cout << "found middle";
                }

        }

}
*/







int main()
{
        vector <int> container = {5, 11, 36, 41, 49, 72, 93,};

        for (int i = 0; i < container.size(); i++)
        {
                cout << container.at(i) << " ";

        }
        cout << endl;

        binsearch(container, 41);
        //binary_search(container);
return 0;
}
