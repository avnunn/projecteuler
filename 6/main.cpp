//Anthony Nunn
//email: avnunn@gmail.com
//site: anthonynunn.org

//Euler 6
//Date: 7/23/201
//http://projecteuler.net/index.php?section=problems&id=6

//Problem:
//The sum of the squares of the first ten natural numbers is,
//
//12 + 22 + ... + 102 = 385
//The square of the sum of the first ten natural numbers is,
//
//(1 + 2 + ... + 10)2 = 552 = 3025
//Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025  385 = 2640.
//
//Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

#include <iostream>
using namespace std;

int main(){
	unsigned long long n = 100;

	unsigned long long sumOfNaturalsSqaured = ((((n*n) + n) * ((n*n) + n)) / 4);
	unsigned long long sumOfSqauredNaturals = (((n*n) + n) * ((2*n) + 1) / 6);

	unsigned long long answer = sumOfNaturalsSqaured - sumOfSqauredNaturals;

	//if we simplify the solution..
	//n(n+1)(3n+2)(n-1)/12 = simplified
	unsigned long long answer2 = ((n*(n+1)*(3*n +2)*(n-1))>>2)/3;

	return 0;
}

/*Description of the solutions

The sum of natural numbers to n is a triangle number.
http://en.wikipedia.org/wiki/Triangular_number

The sum of squares of natural numbers n is:
http://www.math.com/tables/expansion/power.htm

So just subtract the two.
*/