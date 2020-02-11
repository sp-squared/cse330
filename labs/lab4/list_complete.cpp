#include <iostream>
#include <cstdlib>
#include <ctime>
#include "list_complete.h"

using namespace std;

void rand_seed()
{
	int seed = static_cast<int>(time(0));
	srand(seed);
}

// random integer between a and b;
int rand_int(int a, int b)
{
	return a + rand() % (b - a + 1);
}

template <typename T>
void print_list(List<T> lst)
{
	cout << endl;
	typename List<T>::iterator itr;
	for (itr = lst.begin(); itr != lst.end(); ++itr)
		cout << *itr << " ";
	cout << endl;
}

int main()
{
	List<int> mylst;
	rand_seed();
	int rnum;
	for (int i = 1; i <= 15; i++)
	{
		rnum = rand_int(1, 50);
		mylst.push_back(rnum);
	}
	print_list(mylst);

	int tofind1, tofind2;

	cout << "Enter item to find: ";
	cin >> tofind1;
	cout << endl << endl;
	
	List<int>::iterator found = mylst.find(tofind1);
	if (found != mylst.end())
	{
		cout << "Found " << tofind1 << " in list" << endl;
		cout << "Here it is again: " << *found << endl << endl;
	}
	else
		cout << tofind1 << " is not in the list" << endl << endl;

	cout << "Enter another item to find: ";
	cin >> tofind2;
	cout << endl << endl;

	found = mylst.find(tofind2);
	if (found != mylst.end())
	{
		cout << "Found " << tofind2 << " in list" << endl;
		cout << "Here it is again: " << *found << endl << endl;
	}
	else
		cout << tofind2 << " is not in the list" << endl << endl;

	cout << "Self-organizing finding of " << tofind1 << "..." << endl;
	mylst.selforg_find(tofind1);
	print_list(mylst);
	cout << endl;
	cout << "Self-organizing finding of " << tofind2 << "..." << endl;
	mylst.selforg_find(tofind2);
	print_list(mylst);
	cout << endl << endl;
	
	rnum = rand_int(1, 100);
	cout << "Circulating from beginning of list " << rnum << " steps:"
		<< endl;
	found = mylst.circulate(mylst.begin(), rnum);
	cout << "... the iterator stops at item " << *found
		<< endl << endl;
	return 0;
}