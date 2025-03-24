#include <iostream>
	
using namespace std;
	
int main() {
	int num;
	
	cout << "Hello, world!\n";
	cout << "Enter a number: ";
	cin >> num;
	
	if (num % 3 == 0 && num % 5 == 0) {
	cout << "FizzBuzz";
	}
	
	else if (num % 3 == 0) {
	cout << "Fizz";
	}
	
	else if (num % 5 == 0) {
	cout << "Buzz";
	}
	
	else {
	cout << "Not FizzBuzz";
	}
	
} // end
