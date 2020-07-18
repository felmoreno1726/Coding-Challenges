#include <iostream>
#include <math.h>
#include <list>
using namespace std;

bool is_prime(int num){
	for (int i=2; i < num; i++){
		if (num % i == 0){
			return false;
		}
	}
	return true;
}

int largest_power_of(int base, int treshold) {
	/**
	 * @param base the value which power must not exceed treshold.
	 * @return the highest power of base that is smaller than the treshold.
	 */
	int exponent;
	for (exponent = 0; pow(base, exponent) < treshold; exponent++) {
	}
	return exponent - 1;
}

int least_common_multiple(int treshold){
	/**
	 * Computes the least common multiple of all numbers smaller than or equal the treshold.
	 * @param treshold the largest number to compute the least common multiple for.
	 * @return the least common multiple of all numbers under the treshold.
	 */
	int least_common_multiple = 1;
	list<int> primes_list;
	//find the primes under the treshold
	for (int i = 2; i < treshold ; i++){
		if (is_prime(i)) {
			primes_list.push_back(i);
			cout << "Found prime: " << i << "\n";
		}
	}
	//cout << "Primes list: " << primes_list << "\n";
	//find the largest power of each prime that is smaller than the treshold
	for (int prime; !primes_list.empty(); primes_list.pop_front()) {
		prime = primes_list.front();
		//multiply prime to their highest power
		int prime_largest_power = pow(prime, largest_power_of(prime, treshold));
		cout << "Prime: " << prime << " largest power: " << prime_largest_power << "\n";
		least_common_multiple *= prime_largest_power;
		cout << "updated LCM: " << least_common_multiple << "\n";
	}
	return least_common_multiple;
}

int main() {
	/**
	 *
	2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
	What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
	*/
	int answer = least_common_multiple(20);
	cout << "Answer: " << answer << "\n";
	return 0;
}
