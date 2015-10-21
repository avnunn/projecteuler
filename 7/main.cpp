//Anthony Nunn 05/09/12
//Project Euler 7
//---------------
//By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
//What is the 10 001st prime number?
//---------------
//Answer: 104743

#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ULLONG;

int main(){
	const ULLONG N_PRIME_NUMBER = 10001;	//Finding the Nth prime number
	vector <ULLONG> primes;					//hold all the primes

	primes.push_back(2);

	//loop through numbers till you find the Nth prime number
	for (ULLONG i = 3; primes.size() != N_PRIME_NUMBER; ++i){
		bool isPrime = true;
		
		//check to see if number is prime
		for (int j = 0; j < primes.size(); ++j){
			//if number is divisible then it is not a prime
			if ((i % primes[j]) == 0){
				isPrime = false;
				break;
			}
		}

		//if number was prime add it to our list
		if (isPrime){
			primes.push_back(i);
		}
	}

	cout << primes.back() << " is the " << N_PRIME_NUMBER << "th number." << "\n";
	return 0;
}