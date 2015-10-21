//Anthony Nunn 05/09/12
//Project Euler 4
//---------------
//A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 99.
//Find the largest palindrome made from the product of two 3-digit numbers.
//---------------
//Answer: 906609

#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ULLONG;

//puts each digit in reverse into an array then builds that number to compare
bool isNumPalindrone(ULLONG num);

int main(){
	const ULLONG DIGIT_START = 999;	//largest three digit number
	ULLONG a = DIGIT_START;
	ULLONG b = a;

	ULLONG largestPalindrone = 0;

	while (a > 0){
		b = a;
		while (b > 0){
			ULLONG product = a*b;
			--b;

			if (product < largestPalindrone) continue;

			if (isNumPalindrone(product)){
				if (largestPalindrone < product)
					largestPalindrone = product;
			}
			
		}

		--a;
	}
	
	cout << largestPalindrone << " is the largest palindrome made from the product of two 3-digit numbers." << "\n";
	return 0;
}

bool isNumPalindrone(ULLONG num){
	vector<int> reversedDigits;
	ULLONG reverse = num;
	
	//get the reversed digits
	while (reverse != 0){
		reversedDigits.push_back(reverse%10);
		reverse /= 10;
	}

	reverse = 0;
	
	//create the reversed number
	for (int pow = 1; !reversedDigits.empty(); pow *= 10){
		reverse += reversedDigits.back() * pow;
		reversedDigits.pop_back();
	}

	//compare
	if (reverse == num) return true;
	else return false;
}