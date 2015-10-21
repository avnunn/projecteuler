//Anthony Nunn
//email: avnunn@gmail.com
//site: anthonynunn.org

//Euler 9
//Date: 7/12/2010
//http://projecteuler.net/index.php?section=problems&id=9

//Problem:
//A Pythagorean triplet is a set of three natural numbers, a  b  c, for which,
//
//a^2 + b^2 = c^2
//For example, 3^2 + 4^2 
///= 9 + 16 = 25 = 52.
//
//There exists exactly one Pythagorean triplet for which a + b + c = 1000.
//Find the product abc.

#include <iostream>
using namespace std;

int main(){
	//variables to clarify
	int a = 0;	//a < b
	int b = 0;	//b < c
	int c = 0;

	for (int i = 1; (i < 333); ++i){
		for (int j = i + 1; j < 500; ++j){
			a = i;
			b = j;
			c = 1000 - b - a;

			if ((a*a + b*b - c*c) == 0){
				cout << a << " " << b << " " << c << "\n";
				cout << a*b*c << "\n";

				return 0;
			}
		}
	}
}