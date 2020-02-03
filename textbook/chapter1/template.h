#ifndef TEMPLATE_H
#define TEMPLATE_H
#include <iostream>
#include <vector>
using namespace std;
template <typename T>
const T & findMax(const vector <T> & a)
{
        int maxIndex = 0;
        for (int i = 1; i < a.size(); ++i)
        {
                if (a [maxIndex] < a[i])
                {
                                maxIndex = i;
                }
        }
        return a [maxIndex];
}
#endif
