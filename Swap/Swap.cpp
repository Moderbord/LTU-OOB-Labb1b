#include "pch.h"
#include <iostream>

using namespace std;

void swapNo(float &x, float &y);

int main()
{
	float a = 5, b = 7;

	swapNo(a, b);

	cout << a << " " << b;
}

void swapNo(float &x, float &y)
{
	float t = x;

	x = y;
	y = t;
}
