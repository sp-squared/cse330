#include <iostream>
#include "vector.h"
using namespace std;

int main()
{	Vector <int> :: iterator itr;
	Vector <int> v1;
	v1.push_back(43);
	v1.push_back(24);
	v1.push_back(234);

	/*for (itr = v1.begin(); itr !=v1.end(); ++itr)
	{
		cout << *itr << " ";
	}*/

	cout << endl;

	v1.erase(0);
	v1.insert(2,54);

	/*for (itr = v1.begin(); itr !=v1.end(); ++itr)
	{
		cout << *itr << " ";
	}*/

	itr = v1.begin();
	while( itr !=v1.end( ) )
	{
		cout << *itr++ << endl;
	}

return 0;
}
