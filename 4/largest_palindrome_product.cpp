#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;



int make_palindrome_from_top(int palindrome_top) {
	string palindrome_bottom_str = to_string(palindrome_top);
	reverse(palindrome_bottom_str.begin(), palindrome_bottom_str.end());
	string palindrome_str = to_string(palindrome_top) + palindrome_bottom_str;
	return stoi(palindrome_str);
}

int largest_palindrome_product(int num_digits){
	/**
	 * finds the largest palindrome that is the product of two number with num_digits.
	 * @param num_digits defines the number of digits that the two factors must have.
	 * @return the largest palindrome number that is the product of num_digits numbers.
	 */
	int palindrome_top = 997;
	int sqrt_palindrome;
	bool palindrome_not_found = true;
	while (palindrome_not_found){
		int palindrome = make_palindrome_from_top(palindrome_top);
		//attempt to factorize the palindrome
		sqrt_palindrome = (int)sqrt(palindrome);
		for (int divisor = sqrt_palindrome; divisor < 999; divisor++){
			if (palindrome % divisor == 0) {
				//check that quotient is 3 digits long
				int quotient = palindrome / divisor;
				if (100 <= quotient <= 999){
					return palindrome;
				}
			}
		}
		//decrease palindrome top to search the following largest palindrome
		palindrome_top -= 1;
	}
	return 0;
}

int main() {
	/**
	A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
	Find the largest palindrome made from the product of two 3-digit numbers.
	*/
	int answer = largest_palindrome_product(3);
	std::cout << "Answer: " << answer << "\n";
	return 0;
}

