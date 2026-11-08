#include <bits/stdc++.h>
using namespace std;

double f (double x) {
	return (x*x*x - 4*x - 9); //x^3 - 4x - 9
}

double df (double x) {
	return (3*x*x - 4);
}

int main () {
	double x, tol;
	int max_iteration;

	cout << "Enter x: "; cin >> x;
	cout << "Enter tollerance: "; cin >> tol;
	cout << "Enter maximum iterations: "; cin >> max_iteration;

	if (df(x) == 0) {
		cout << "Error." << endl;
		return 0;
	}

	double x0 = 0;
	for (int i = 1; i <= max_iteration; i++) {
		x0 = x - (f(x) / df(x));

		if (abs (f(x0)) < tol) {
			cout << "Root: " << x0 << endl;
			cout << "f(x0): " << f(x0) << endl;
			cout << "iteration: " << i << endl;
			return 0;
		}

		x = x0;
	}
	cout << "maximum iteration reached." << endl;
	cout << "Root: " << x << endl;
	cout << "f(x0): " << f(x) << endl;
}