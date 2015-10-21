#include <iostream>

class Digit{
public:
	Digit* left;
	Digit* right;
	
	short digit;
	short toAdd;
	
	Digit(){
		this->left = NULL;
		this->right = NULL;
		
		this->digit = 0;
		this->toAdd = 0;
	}
	
	void multiplyByTwo(){
		this->digit *= 2;
		this->digit += this->toAdd;
		this->toAdd = 0;
		
		bool recurse = true;
		
		if (left == NULL){
			left = new Digit();
			left->right = this;
			recurse = false;
		}
		
		if (digit >= 10){
			left->toAdd += 1;
			digit -= 10;
		}
		
		if (recurse) this->left->multiplyByTwo();
	}
	
	int sumOfDigits(){
		Digit* current = this;
		int sum = 0;
		
		for(;;){
			if (current == NULL) break;
			sum += current->digit;
			current = current->left;
		}
		
		return sum;
	}
};

int main(){
	Digit number;
	number.digit = 1;
	
	for (int i = 0; i < 1000; ++i){
		number.multiplyByTwo();
	}
	
	int sum = number.sumOfDigits();
	cout << sum << "\n";
	
	return 0;
}