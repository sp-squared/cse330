#include <iostream> 
#include <vector>
#include <cassert>
using namespace std;

// Colin Morris-Moncada
// CSE 330 Lab 1
// No Sort Median Function, Recursive Median Function, Maximum Value Function

// No Sort Function
int median(vector <int> nums)
{
 	// ensure that size is odd
	assert(nums.size() % 2 != 0); 
	// splits vector in two sections
	int half = nums.size() / 2; 
	cout << endl;
	cout << " Half =  " << half << endl;
	
	// nested for loop
	for (int i = 0; i < nums.size(); i++)
	{
		// k counter
		int k = 0;
		for (int j = 0; j <nums.size(); j++)
		{	
			if (nums[j] > nums[i])
			{
				k = k + 1;
			}
			
		}
			if (k == half)
			{
				cout << " The Median = ";
				return nums[i];
			}
	}
 	return -1;
}


// Recursive Function
void recur(int i , vector <int> nums)
{
	if(i < 0)
	{
		return;
	}
	if(i == nums.size())
	{
		return;
	}
	
	cout << "|"<< nums[i] << "|";
	recur(i+1, nums);
}	
	
// Maximum Value Function
// ....

int main()
{
	// variable declarations
	vector <int> numlist;
	int next;
	int how_many;
	 
	// input from user
	cout << " How many elements? (odd) : ";
	cin >> how_many;
	
	// push each number into the vector	
	for (int i = 0; i < how_many; i++)
	{
		cout << "Num : ";
		cin >> next;
		numlist.push_back(next);
	}
	
	// prints the vector in order of what was pushed 
	for (int i = 0; i <  numlist.size(); i++)
	{
		cout << "|" << numlist[i] << "|";
	}
	
	// call the median function
	int m = median(numlist);
	cout << m;
	cout << endl;
	
	// call the median function w/ recursion
	recur(0,numlist);
	cout << endl;
return 0;
}
