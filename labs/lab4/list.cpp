#include "list.h"
#include <cstdlib>
#include  <iostream>
using namespace std;

int main()
{	List <int> :: iterator itr;
	List <int> myList;
	myList.push_back(10);
	myList.push_back(11);
	myList.push_back(12);
	myList.push_back(13);
	myList.push_back(14);
	myList.push_back(15);
	myList.push_back(16);
	myList.push_back(17);
	myList.push_back(18);
	myList.push_back(19);
	myList.push_back(20);
	myList.push_back(21);
	myList.push_back(22);
	myList.push_back(23);
	myList.push_back(24);
	myList.push_back(25);

	myList.print();
	cout << endl;
	myList.find(26);
	myList.find(15);



	//  Prints all the items in the list
	/*

	for (itr = myList.begin(); itr != myList.end(); ++itr)
	{
		cout << "[" << *itr << "]";

	}

	*/
	//cout << endl;

	// Finds integer value by iterating through List
	// If value is not found back() is given
	/*

	int value = 0;
	for ( itr = myList.begin(); itr != myList.end() ; itr ++ )
	{
		if ( value == *itr )
		{
			cout << "[" << *itr << "]" << endl;
		}

	}
	cout << "[" << myList.back() << "]" << endl;

	*/
return 0;
}
