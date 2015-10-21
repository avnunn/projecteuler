//Anthony Nunn
//email: avnunn@gmail.com
//site: anthonynunn.org

//Euler 3
//Date:	7/12/2010
//http://projecteuler.net/index.php?section=problems&id=3

//Problem
//The prime factors of 13195 are 5, 7, 13 and 29.
//What is the largest prime factor of the number 600851475143?

#include <vector>
using std::vector;

typedef unsigned long long ullong;

#define DEFAULT_E_NUMBER 600851475143

int main(int argc, char** argv){
	ullong number = 0;				//to hold number to find largest prime factor
	vector<ullong> primeFactors;	//prime factors of number

	number = DEFAULT_E_NUMBER;

	for (ullong i = 2; number != 1;){
		if ((number % i) == 0){
			number /= i;
			primeFactors.push_back(i);
		}

		else ++i;
	}

	return 0;
}