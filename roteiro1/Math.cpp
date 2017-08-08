//
//  Math.cpp
//
//  Created by Eiji Adachi Medeiros Barbosa 
//

#include "Math.hpp"

int add(int a, int b)
{
	return t_add (a, b, b);
}

int t_add (int a, int b, int sum)
{
	if (a == 0) {
		return sum;
	} else {
		return t_add (a - 1, b, sum + 1);
	}
}

int subtract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
	return t_multiply (a, b, 0);
}

int t_multiply (int a, int b, int mult)
{
	if (a == 0) {
		return mult;
	} else {
		return t_multiply (a - 1, b, mult + b);
	}
}

int divide(int a, int b)
{
	return a / b;
}

int factorial(int a)
{
	return t_factorial (a, 1);
}

int t_factorial(int a, int fact)
{
	if (a == 0) {
		return fact;
	} else {
		return t_factorial (a - 1, a * fact);
	}
}
