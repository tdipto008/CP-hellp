#include <bits/stdc++.h>
using namespace std;

double f(double x) { return x * x * x - x - 2; }

int main() {
	double x1, x2, tol;
	int max_iter;

	cout << "          FALSE POSITION METHOD\n";
	cout << "============================================\n";
	cout << "Enter lower bound (x1): "; cin >> x1;
	cout << "Enter upper bound (x2): "; cin >> x2;
	cout << "Enter tolerance: "; cin >> tol;
	cout << "Enter maximum iterations: "; cin >> max_iter;

	if (f(x1) * f(x2) >= 0) {
		cout << "\nError: f(x1) and f(x2) must have opposite signs.\n";
		return 0;
	}

	cout << "\n";
	cout << "---------------------------------------------------------------\n";
	cout << setw(5)  << "Iter"
		<< setw(15) << "x1"
		<< setw(15) << "x2"
		<< setw(15) << "x0"
		<< setw(15) << "f(x0)";
	cout << "---------------------------------------------------------------\n";

	double x0 = 0;
	for (int i = 1; i <= max_iter; i++) {
		x0 = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));
		double fx0 = f(x0);

		cout << fixed << setprecision(8);
		cout << setw(5)  << i
			<< setw(15) << x1 << setw(15) << x2 << setw(15) << x0
			<< setw(15) << fx0 << '\n';

		if (abs(fx0) < tol) {
			cout << "---------------------------------------------------------------\n";
			cout << "\nRoot = " << x0 << '\n';
			cout << "f(root) = " << fx0 << '\n';
			cout << "Iterations = " << i << '\n';
			return 0;
		}

		if (f(x1) * fx0 < 0) x2 = x0;
		else x1 = x0;
	}

	cout << "---------------------------------------------------------------\n";
	cout << "\nMaximum iterations reached.\n";
	cout << "Approximate root = " << x0 << '\n';

	return 0;
}