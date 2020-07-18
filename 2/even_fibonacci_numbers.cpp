#include <iostream>
#include <tuple>
using namespace std;


int even_fibonacci_sum(int treshold){
	/**
	 * @param treshold the upper bound on the Fibonacci numbers to add.
	 * @return the sum of even Fibonacci numbers under treshold.
	 */
	int f1 = 1;
	int f2 = 2;
	int total_sum = 0;
	int i = 1;
	int tmp;
	while (f2 < treshold) {
		//the fibonacci number have the following pattern
		//f: (odd, even, odd), (odd, even, odd), (odd, even, odd), (odd, even, odd) ...
		//i: (0,   1,    2  ), (3,   4,    5  ), (6,   7,    9  ), (10 , 11,   12 ) ...
		std::cout << "(f1: " << f1;
		std::cout << ", f2: " << f2 << ")\n";
		if (i % 3 ==  1) {
			std::cout << "adding!\n";
			total_sum += f2;
			std::cout << "running sum: " << total_sum << "\n";
		}
		tmp = f2;
		f2 = f1 + f2;
		f1 = tmp;
		//std::tie(f1, f2) = std::make_tuple(f2, f1+f2);
		i++;
	}
	return total_sum;
}

int main() {
	/**
	 *
	Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:
	1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
	By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
	*/
	int treshold = 4000000;
	int ans = even_fibonacci_sum(treshold);
	std::cout << "Answer: " << ans << "\n";
	return 0;
}
