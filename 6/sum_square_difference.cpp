#include <iostream>
using namespace std;

int sum_square_difference(int treshold){
	int sum = 0;
	for (int i = 1; i <= treshold; i++){
		for (int j=1; j <= treshold; j++){
			if (i != j){
				sum += i * j;
			}
		}
	}
	return sum;
}

int main(){
	/**
	 * The sum of the squares of the first ten natural numbers is, 
	 * 12+22+...+102=385
	 * The square of the sum of the first ten natural numbers is,
	 * (1+2+...+10)2=552=3025
	 * Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025−385=2640.
	 * Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
	 */
	int treshold = 100;
	int answer = sum_square_difference(treshold);
	cout << "Answer: " << answer << "\n";
	return 0;
}
