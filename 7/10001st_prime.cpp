#include <iostream>
#include <list>
using namespace std;

int i_th_prime(int i){
	/**
	 * Finds the i_th smallest prime. Requires i >= 1
	 * @param i the smallest prime to find
	 * @return the i_th number in 1,2,... that is a prime.
	 */
	list<int> primes;
	primes.push_front(2);
	//iterate over odd numbers to find primes
	for (int value = 3; primes.size() < i; value +=2 ){
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
			cout << "found prime: " << value << "\n";
			primes.push_back(value);
		}
	}
	return primes.back();
}

int main(){
	/**
	 *
	By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
	What is the 10 001st prime number?
	*/
	int i = 10001;
	int answer = i_th_prime(i);
	cout << "Answer: " << answer << "\n";
	return 0;
}
