#include <iostream>
#include <algorithm>
using namespace std;
#include "full_list.h"
int main()
{
        /*
        // initialize a List of Ints called list
        List <int> list;

        // Push Back value 6
        list.push_back(6);

        // Outputs 1 for [6]
        std::cout << list.size() << std::endl;

        // Outputs 0 because the list is not empty
        std::cout << list.empty() << std::endl;

        // Push back value 10
        list.push_back(10);

        // Outputs 10 because it is in back
        std::cout << list.back() << std::endl;
        */
        List <int> :: iterator itr;
        List <int> myList;
        myList.push_back(56);
        myList.push_back(3436);
        myList.push_back(235);
        myList.push_back(245325);
        myList.push_back(4654);
        myList.push_back(452);
        myList.push_back(54353);
        myList.push_back(13246);
        myList.push_back(235);
        myList.push_back(6985);
        myList.push_back(235);

        for (itr = myList.begin(); itr != myList.end(); itr++)
        {
                cout << *itr << endl;
        }
        cout << "List has " << myList.size() << " elements" << endl;

        myList.pop_back();
        cout << endl;

        for (itr = myList.begin(); itr != myList.end(); itr++)
        {
                cout << *itr << endl;
        }

        cout << "List has " << myList.size() << " elements" << endl;



return 0;
}
