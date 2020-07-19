#include <iostream>
#include <tuple>
#include <math.h>
#include <cassert>
using namespace std;

array<float, 2> solve_quadratic_system(double a, double b, double c){
	array<float, 2> roots;
	float discriminant = b*b - 4*a*c;
	if (discriminant == 0){
		roots[1], roots[2] = -b / (2*a);
	}
	else if (discriminant > 0) {
		roots[0] = (-b + sqrt(discriminant)) / (2 * a);
		roots[1] = (-b - sqrt(discriminant)) / (2 * a);
	}
	else {
		//roots are imaginary, just return (0, 0)
		roots[0], roots[1] = 0;
	}
	return roots;
}

tuple<int, int, int> find_special_tuple() {
	/**
	 * Finds a Pytagoean triplet (a, b, c) such that a + b + c = 1000
	 * @return the special triplet as a tuple object
	 */
	// Requirements
	// a < b < c
	// a^2 + b^2 = c^2
	// a + b + c = 1000
	// 
	// Implications
	// a^2 + b^2 = (1000 -a -b)^2
	// => 0 = 1000^2 -2000 (a + b) + 2ab
	// => 1000 (a + b) - (ab) = 1000 (500)
	// => 1000 | ab
	// => ab = 1000x for x \in \Z+
	// => a + b - x = 500
	// => a + (1000x/b) - x  = 500
	// => a^2 - a(500 + x) + 1000x = 0
	
	bool solution_not_found = true;
	array<float, 2> roots;
	int a, b, c;
	int x = 1;
	//since x + c = 500 => x < 500
	while (x < 500 && solution_not_found) {
		roots = solve_quadratic_system(1, -500-x, 1000*x);
		// check if any of the root solution work
		for (int i =0; i < 2; i++){
			float root = roots[i];
			if (root> 0) {
				//check that the root is an integer value
				//if (ceilf(root) == floorf(root)) {
				if (true) {
					a = round(root);
					cout << "\na = " << a << ", ";
					//check that b can be constructed
					if (1000 % a == 0){
						b = 1000 * x / a;
						cout << "b= " << b << ", ";
						c = 1000 - a -b;
						cout << "c= " << c << "";
						//check the Pytagorean condition
						if (a*a + b*b == c*c) {
							cout << "\nSolution found!\n";
							solution_not_found = false;
							break;
						}
					}
				}
			}
		}
		x++;
	}
	return make_tuple(a, b, c);
}


int main() {
	/**
	 *
	A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
	a2 + b2 = c2
	For example, 32 + 42 = 9 + 16 = 25 = 52.
	There exists exactly one Pythagorean triplet for which a + b + c = 1000.
	Find the product abc.
	*/
	tuple<int, int, int> special_tuple = find_special_tuple();
	int answer = get<0>(special_tuple) * get<1>(special_tuple) * get<2>(special_tuple);
	cout << "Answer: "  << answer << "\n";
	return 0;
}
