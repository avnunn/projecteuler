//Anthony Nunn
//email: avnunn@gmail.com
//site: anthonynunn.org

//Euler 1
//Date: 7/12/2010
//http://projecteuler.net/index.php?section=problems&id=1

//Problem:
//If we list all the natural numbers below 10 that are multiples of 3 or 5, 
//we get 3, 5, 6 and 9. The sum of these multiples is 23.
//
//Find the sum of all the multiples of 3 or 5 below 1000.


//-------
//Arguments
//-------
//In the example, 10 would be "belowThis", 3 or 5 will be "multiples"
//
//
//This program works as follows.
//
//-Pass in arguments
//-First argument passed in is "belowThis"
//-Every subsequent argument is "multiples"
//-------
//
//
//-------
//Returns
//-------
//Returns -1 for failure.
//Returns the sum if it succeeded.
//-------

#include <stdio.h>
#include <vector>
#include <assert.h>
#include <set>

using std::vector;
using std::set;

#define NOT_ENOUGH_ARGUMENTS	-1
#define ZERO_ARGUMENT			-2

#define MINIMUM_ARGUMENTS		3
#define	DIRECTORY_ARGUMENT		0
#define BELOW_THIS_ARGUMENT		1

typedef unsigned int uint;
typedef set<unsigned int>::iterator set_uint_it;

int main(int argc, char** argv){
	if (argc < MINIMUM_ARGUMENTS) return NOT_ENOUGH_ARGUMENTS;

	uint belowThis		= 0;
	uint sum			= 0;

	vector<uint> multiples;
	set<uint> multiplesOf;


	//Make sure we get the correct arguments for this program
	for (int i = 0; i < argc; ++i){
		if (i == DIRECTORY_ARGUMENT) continue;
		else if (i == BELOW_THIS_ARGUMENT){
			belowThis = atoi(argv[i]);
			continue;
		}

		multiples.push_back(atoi(argv[i]));
		if (multiples.back() == 0) return ZERO_ARGUMENT;
	}

	if (multiples.size() == 0) return NOT_ENOUGH_ARGUMENTS;

	
	//finds all the multiples of (multiples) under (belowThis)
	for (uint i = 0; i < multiples.size(); ++i){
		for (uint j = multiples[i]; j < belowThis; j += multiples[i]){
			multiplesOf.insert(j);
		}
	}

	//sum of all the multiples of (multiples) under (belowThis)
	for (set_uint_it i = multiplesOf.begin(); i != multiplesOf.end(); ++i){
		sum += *i;
	}

#if _DEBUG

	//Printint out information
	printf("If we list all the natural numbers below %i", belowThis);
	printf("that are multiples of \n");

	for (int i = 0; i < multiples.size(); ++i){
		printf(" %i", multiples[i]);
	}

	printf("\n\nwe get \n");

	for (set_uint_it i = multiplesOf.begin(); i != multiplesOf.end(); ++i){
		printf(" %i", *i);
	}

	printf("\n\nThe sum of these multiples is %i\n", sum);

#endif

	return sum;
}
