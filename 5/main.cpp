//Anthony Nunn
//email: avnunn@gmail.com
//site: anthonynunn.org

//Euler 5
//Date: 7/21/2010
//http://projecteuler.net/index.php?section=problems&id=5

//Problem:
//2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
//
//What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

#include <iostream>
#include <vector>
#include <map>

using std::cout;
using std::map;
using std::vector;

typedef unsigned long long ullong;

int main(int argc, char** argv){
	ullong number = 0;				//used for a temporary value and to hold answer at the end
	ullong start = 1;
	ullong end = 20;

	map<ullong, ullong> primes;
	for (ullong j = start; j <= end; ++j){
		map<ullong, ullong> primeFactors;	//prime factors of number
		number = j;

		//find all this numbers prime factors
		for (ullong i = 2; number != 1;){
			if ((number % i) == 0){
				number /= i;
				++primeFactors[i];
			}

			else ++i;
		}

		//check to see if it contains a larger amount of any one prime
		//if it does, then replace it in our prime list
		for (map<ullong, ullong>::iterator i = primeFactors.begin(); i != primeFactors.end(); ++i){
			if (primes[i->first] < i->second) primes[i->first] = i->second;
		}
	}

	number = 1;
	//go through every prime
	for (map<ullong, ullong>::iterator i = primes.begin(); i != primes.end(); ++i){
		//and multiply by the prime the amount it is
		for (ullong j = 0; j < i->second; ++j){
			number *= i->first;
		}
	}

	cout << "The smallest positive number that is evenly\ndivisible by all the numbers from " << start << " to " << end << " is:\n";
	cout << number << "\n";

	return number;
}