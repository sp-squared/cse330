#include <iostream>
#include "VectorL3new.h"
using namespace std;

int main()
{	cout << "void erase(int k) shown here : " << endl;
	Vector <int> :: iterator itr;
	Vector <int> v1;
	v1.push_back(2);
	v1.push_back(4);
	v1.push_back(6);
	v1.push_back(8);
	v1.push_back(10);
	v1.push_back(12);
	v1.push_back(14);
	v1.push_back(16);

	for (itr = v1.begin(); itr !=v1.end(); ++itr)
	{
		cout << *itr << " ";
	}
	cout << endl;
	v1.insert(3,7);
	for (itr = v1.begin(); itr !=v1.end(); ++itr)
	{
		cout << *itr << " ";
	}
	cout << endl;

	Vector <int> v2
	cout << "void insert (int k, T x) shown here : " << endl;
	v1.push_back(2);
	v1.push_back(4);
	v1.push_back(6);
	v1.push_back(8);
	v1.push_back(10);
	v1.push_back(12);
	v1.push_back(14);
	v1.push_back(16);
	
return 0;
}
