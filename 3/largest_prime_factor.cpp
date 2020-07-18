#include <iostream>
using namespace std;

unsigned long long int largest_prime_factor(unsigned long long int num, unsigned long long int base_divisor= 3) {
	/**
	 * Searches for the largest integer number in the prime factor decomposition of number.
	 *
	 * @param num the number to extract largest prime factor from.
	 * @return largest prime factor of num.
	 */
	//Base case
	std::cout << "Finding largest prime factor for: " << num << "\n";
	std::cout << "starting from base divisor: " << base_divisor << "\n";
	if (num == 1){
		return 1;
	}
	else if (num % 2 == 0 ){
		//int div = 2;
		return std::max<unsigned long long int>(2, largest_prime_factor(num / 2));
	}
	if (base_divisor > num/2) {
		//already explored all potential divisors
		return num;
	}
	//iterate over potential prime factors
	for (unsigned long long int i = base_divisor; i < num / 2; i+=2){
		//if prime factor divides num
		if (num % i == 0){
			return std::max(i, largest_prime_factor(num / i, i));
		}
	}
	//then found no prime dividers less than itself. num is prime!
	std::cout << num << " is prime!\n";
	return num;
}

int main(){
	/**
	 *
	The prime factors of 13195 are 5, 7, 13 and 29.
	What is the largest prime factor of the number 600851475143 ?
	 *
	 */
	unsigned long long int num = 600851475143;
	std::cout << "Input: " << num << "\n";
	unsigned long long int answer = largest_prime_factor(num);
	std::cout << "Answer: " << answer << "\n";
	return 0;
}
