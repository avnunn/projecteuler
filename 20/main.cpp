#include <iostream>

class Digit{
public:
	Digit* left;
	Digit* right;
	
	long digit;
	long toAdd;
	
	Digit(){
		this->left = NULL;
		this->right = NULL;
		
		this->digit = 0;
		this->toAdd = 0;
	}
	
	void multiplyBy(int num){
		this->digit *= num;
		this->digit += this->toAdd;
		this->toAdd = 0;
		
		bool recurse = true;
		
		if (this->left == NULL){
			this->left = new Digit();
			this->left->right = this;
			recurse = false;
		}
		
		if (this->digit >= 10){
			this->left->toAdd += this->digit/10;
			this->digit = (this->digit%10);
		}
		
		if (recurse) this->left->multiplyBy(num);
		else if (this->left->toAdd != 0){
			this->left->multiplyBy(1);
		}
	}
	
	unsigned long sumOfDigits(){
		Digit* current = this;
		unsigned long sum = 0;
		
		for(;;){
			if (current == NULL) break;
			sum += current->digit;
			current = current->left;
		}
		
		return sum;
	}
	
	void print(){
		Digit* current = this;
		Digit* previous = this;
		bool strip = true;
		
		//get to the left most digit
		for (;;){
			if (current == NULL) break;
			previous = current;
			current = current->left;
		}
		
		current = previous;
		
		for (;;){
			if (current == NULL) break;
			if (current->digit) strip = false;
			if (!strip) cout << current->digit;
			current = current->right;
		}
	}
};

int main(){
	Digit number;
	number.digit = 1;
	
	for (int i = 100; i >= 2; --i){
		cout << "Multiply ";
		number.print();
		cout << " by " << i << " = ";
		number.multiplyBy(i);
		number.print();
		cout << "\n";
	}
	
	unsigned long sum = number.sumOfDigits();
	cout << sum << "\n";
	
	return 0;
}