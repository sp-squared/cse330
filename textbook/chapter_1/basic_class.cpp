#include "basic_class.h"
#include <iostream>
using namespace std;
int main ()
{
	IntCell num1;
	num1 = 5;
	cout << "Way 1 : " << num1.IntRead() << endl;
	
	IntCell num2 = 6;
	cout << "Way 2 : " << num2.IntRead() << endl;
	
	IntCell num3 = (7);
	cout << "Way 3 : " << num3.IntRead() << endl; 
	

	num1.IntWrite(0);
	cout << "Way 1 changed : " << num1.IntRead() << endl;
return 0;
}