#include <iostream>
#include <algorithm>
#include "VectorL3new.h"
#include "Random.h"
using namespace std;


template <typename T>
void print_vector(Vector<T> vec)
	{
		for (auto x : vec)
			cout << x << " ";
	cout << endl << endl;
	return;
}

int median(Vector<int> vec)
{
	int half = vec.size() / 2;
	sort(vec.begin(), vec.end());
	if (vec.size() % 2 != 0)
		return vec[half];
	else
		return (vec[half] + vec[half + 1]) / 2;
}

int mean(Vector<int> vec)
{
	int sum = 0;
	for (int i = 0; i < vec.size(); i++)
		sum += vec[i];
	return sum / vec.size() - 1;
}

int main()
{
	Vector<int> myvec;
	rand_seed();
	random_vector_norep(30, 1, 100, myvec, 0);
	print_vector(myvec);

	// remove all even values;
	int i = 0;
	while (true)
	{
		if (i >= myvec.size())
			break;

		if (myvec[i] % 2 == 0)
			myvec.erase(i);
		else
			i++;
	}
	cout << "After removal of all even numbers:" << endl;
	print_vector(myvec);

	// remove all multiples of 3
	Vector<int>::iterator itr = myvec.begin();
	while (true)
	{
		if (itr >= myvec.end())
			break;

		if (*itr % 3 == 0)
			myvec.erase(itr);
		else
			itr++;
	}
	cout << "After removal of all multiples of 3: " << endl;
	print_vector(myvec);

	int med = median(myvec);
	int mn = mean(myvec);

	cout << endl;
	cout << "Median value: " << med << endl;
	cout << "Mean value:   " << mn << endl << endl;

	sort(myvec.begin(), myvec.end());
	cout << "Sorted:" << endl;
	print_vector(myvec);

	// insert median in between smaller and larger value
	for (int i = 0; i < myvec.size() - 1; i++)
	{
		if (myvec[i] <= med && med <= myvec[i + 1])
		{
			cout << "median element " << med << " fits between "
				<< myvec[i] << " and " << myvec[i + 1]
				<< " -- insert it" << endl << endl;
			myvec.insert(i + 1, med);
			break;
		}
	}
	print_vector(myvec);

	
	// insert mean inbetween smaller and larger value
	
	for (itr = myvec.begin(); itr <  myvec.end(); ++itr)
	{
		if (*itr <= mn and mn <= *(itr + 1))
		{
			cout << "mean element " << mn << " fits between " << *itr
				<< " and " << *(itr + 1) << " -- insert it "
				<< endl << endl;
			myvec.insert(itr + 1, mn);
			break;
		}
	}
	print_vector(myvec);

	return 0;
}

