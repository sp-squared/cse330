#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include "Random.h"

using namespace std;

int nosort_median(vector<int> nums)
{
	assert(nums.size() % 2 != 0);
	int half = nums.size() / 2;

	for (int i = 0; i < nums.size(); i++)
	{
		int k = 0;
		for (int j = 0; j < nums.size(); j++)
		{
			if (nums[j] < nums[i])
				k++;
		}
		if (k == half)
			return nums[i];
	}
	return -1; // dummy return; will not go here;
}

int median(vector<int> nums)
{
	assert(nums.size() % 2 != 0);
	int half = nums.size() / 2;

	sort(nums.begin(), nums.end());
	return nums[half];
}

void print_vector(vector<int> vec)
{
	cout << endl;
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
	return;
}

int main()
{
	rand_seed();

	int how_many;
	cout << "How many? (odd) ";
	cin >> how_many;
	cout << endl;

	if (how_many % 2 == 0)
		how_many++;

	vector<int> mynums;
	
	/*
	int next;
	for (int i = 1; i <= how_many; i++)
	{
		cout << "Next number: ";
		cin >> next;
		cout << endl;
		mynums.push_back(next);
	}
	*/
	// how_many many random numbers 1..100 with up to 50% neg values
	random_vector_norep(how_many, 1, 100, mynums,5);

	vector<int> cpmynums(mynums);

	print_vector(mynums);
	cout << "The median element (no sort) is " << nosort_median(mynums) << endl << endl;

	print_vector(cpmynums);
	cout << "The median element (with sort) is " << median(cpmynums) << endl << endl;

	return 0;
}