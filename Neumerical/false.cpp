#include <bits/stdc++.h>
using namespace std;

double f (double x) {
	return (x*x*x - 4*x - 9);
}

int main () {
	double x1, x2, tol;
	int max_iteration;

	cout << "Enter x1: "; cin >> x1;
	cout << "Enter x2 : "; cin >> x2;
	cout << "Enter tollerance: "; cin >> tol;
	cout << "Enter maximum iterations: "; cin >> max_iteration;

	if (f(x1) * f(x2) >= 0) {
		cout << "\nError: f(x1) and f(x2) must have opposite signs.\n";
		return 0;
	}

	double x0 = 0;
	for (int i = 1; i <= max_iteration; i++) {

		x0 = x1 - ((f(x1)*(x2 - x1)) / (f(x2) - f(x1)));

		if (abs (f(x0)) < tol) {
			cout << "Root: " << x0 << endl;
			cout << "f(x0): " << f(x0) << endl;
			cout << "iteration: " << i << endl;
			return 0;
		}

		if (f(x1) * f(x0) < 0) {
			x2 = x0;
		} else {
			x1 = x0;
		}
	}

	cout << "aproximate root : " << x0 << endl;
}