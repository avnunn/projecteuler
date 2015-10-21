//Anthony Nunn
//email: avnunn@gmail.com
//site: anthonynunn.org

//Euler 10
//Date: 7/12/2010
//http://projecteuler.net/index.php?section=problems&id=X

//Problem:
//The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
//Find the sum of all the primes below two million.

#include <iostream>
#include <vector>

using namespace std;

int main(){
	//variables
	vector<bool> numbers;				//will hold all numbers from 0 to 2000000
	numbers.resize(						//resize vector to fit that space and fill it with true
		2000001,		//amount of elements
		char(1));		//what to fill the space with (requires a character, but I want to set it to true)

	vector<unsigned int> primes;		//holds all the prime numbers
	unsigned long long primeSum = 0;	//holds the sum of the prim numbers, unsigned long long to actually fit the number

	cout << "The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17." << "\n";
	cout << "Find the sum of all the primes below two million." << "\n";
	cout << "\n";
	cout << "Calculating..." << "\n";

	//start from 2, the first prime
	for (unsigned int i = 2; i < 2000000; ++i){
		//and if its set to true
		if (numbers[i]){
			//find every multiple of that number from it to 2 million and set it to false
			for (unsigned int j = i+i; j < 2000000; j += i){
				numbers[j] = 0;
			}

			//and then add them to the list
			//and add it to our sum
			primes.push_back(i);
			primeSum += i;
		}

		//if its set false, its not prime, continue on
		else continue;
	}

	cout << "\n";
	cout << "Sum of all the primes below two million is " << primeSum << "\n";
}