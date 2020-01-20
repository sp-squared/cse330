#include <iostream>
#include <vector>
#include "Random.h"
#include "MaxSubSum.h"
using namespace std;

void print_vector(vector<int> v)
{
	cout << endl;
	for (auto x : v)
		cout << x << " ";
	cout << endl;
}

int main()
{
	vector<int> mynums;
	random_vector_norep(25, 1, 1000, mynums, 4);

	cout << "Here are 25 numbers ... " << endl;
	print_vector(mynums);
	cout << endl;

	int ops1;
	int ops4;

	int max1 = max_sub_sum_alg1(mynums, ops1);

	cout << "Alg1 found maximal subsum " << max1 << " with " << ops1 << " additions";
	cout << endl << endl;

	int max4 = max_sub_sum_alg4(mynums, ops4);

	cout << "Alg4 found maximal subsum " << max4 << " with " << ops4 << " additions";
	cout << endl << endl;

	return 0;
}
