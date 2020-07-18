#include <iostream>
using namespace std;


int find_num_multiples_below(int i, int treshold) {
	/**
	 * @param i the value to count multiples of.
	 * @param treshold the value which multiples must not exceed.
	 * @return the number of multiples of i below the treshold.
	 */
	return treshold / i;
	
}

int gaussian_sum(int i){
	/**
	 * Adds all integer numbers from 1 until i
	 * @param i the upper bound on the integers to add
	 * @return the sum of all integer values under i
	 */
	return (i)*(i+1)/2;
}

int main() {
/** 
Problem description:

If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
*/
	int treshold = 1000;
	int multiples_of_3 = find_num_multiples_below(3, treshold);
	int multiples_of_5 = find_num_multiples_below(5, treshold);
	int multiples_of_15= find_num_multiples_below(15, treshold);
	int sum_of_multiples_below_3 = 3 * gaussian_sum(multiples_of_3);
	int sum_of_multiples_below_5 = 5 * gaussian_sum(multiples_of_5 - 1);
	int sum_of_multiples_below_15=15 * gaussian_sum(multiples_of_15);
	// adds the multiples of 3 or 5 and substracts the multiples of 15 since they would otherwise be added twice
	int answer = sum_of_multiples_below_3 + sum_of_multiples_below_5 - sum_of_multiples_below_15;
	std::cout << "Result: " << answer << "\n";
	return 0;
}
