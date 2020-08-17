#include <iostream>
#include <list>
#include <numeric>
#include <cstring>
using namespace std;

long int sum_of_primes(int threshold) {
	/**
	 * Adds all prime numbers under a treshold.
	 * @param treshold bounds the largest prime number to add.
	 * @return the sum of all the prime numbers under the treshold.
	 */
	list<int> primes;
	primes.push_front(2);
	//iterate over odd numbers to find primes
	for (int value = 3; value <= threshold; value += 2) {
		bool is_prime = true;
		//check if value is prime by checking if division with previous primes is 0
		for (list<int>::iterator iter = primes.begin(); iter != primes.end(); iter++){
			//check if prime value can divide current 
			int prime = *iter;
			if (value % prime == 0) {
				is_prime = false;
				//value is not a prime, move on
				break;
			}
		}
		if (is_prime) {
			//cout << "found prime: " << value << "\n";
			primes.push_back(value);
		}
	}
	long long int sum_of_primes = accumulate(primes.begin(), primes.end(), 0);
	return sum_of_primes;
}

long long int sum_of_primes_fast(int threshold) {
	/**
	 * Adds all prime numbers under a treshold.
	 * @param treshold bounds the largest prime number to add.
	 * @return the sum of all the prime numbers under the treshold.
	 */
	//initialize array pointing all values of is_prime to true
	bool is_prime[threshold + 1];
	memset(is_prime, true, threshold +1);
	//iterate over values under the threshold
	for (int val = 2; val*val <= threshold; val++){
		//if value's is_prime is true, then 
		if (is_prime[val]) {
			//update all multiples of val in is_prime array
			for (int factor = 2; val * factor <= threshold; factor++) {
				is_prime[val * factor] = false;
			}
		}
	}
	//sum all values that are true in the is_prime array
	long long int sum_of_primes = 0;
	for (int idx = 2; idx <= threshold; idx++) {
		if (is_prime[idx]){
			sum_of_primes += idx;
		}
	}
	return sum_of_primes;
}

int main() {
	/**
	 *
	The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
	Find the sum of all the primes below two million.
	*/
	int threshold = 2000000;
	//int threshold = 10;
	//int threshold = 11;
	cout << "Threshold: " << threshold << "\n";
	long long int answer = sum_of_primes_fast(threshold);
	cout << "Answer: " << answer << "\n";
	return 0;
}

