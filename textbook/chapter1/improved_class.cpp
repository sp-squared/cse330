#include "improved_class.h"
#include <iostream>
using namespace std;
int main ()
{

/*
	IntCell num1;
	num1 = 5;
	cout << "Way 1 : " << num1.IntRead() << endl;

	IntCell num2 = 6;
	cout << "Way 2 : " << num2.IntRead() << endl;

	IntCell num3 = (7);
	cout << "Way 3 : " << num3.IntRead() << endl;

	int num = 5;
	IntCell test = num;
	cout << "Test : " << num.IntRead(); << endl;

	// This way must be used for explicit constructors
	num1.IntWrite(0);
	cout << "Way 1 changed : " << num1.IntRead() << endl;
*/

	IntCell num1;
	int x;

	cout << "Num 1 : ";
	cin >> x;
	num1.IntWrite(x);
	cout << "User Input Way =  " << num1.IntRead() << endl;


	IntCell num2;
	num2.IntWrite(5);
	cout << "Improved Way = " << num2.IntRead() << endl;
return 0;
}
