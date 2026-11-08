#include <bits/stdc++.h>
using namespace std;

double f(double x) { return x * x * x - x - 2; }
double df(double x) { return 3 * x * x - 1; }

int main() {
	double x, tol;
	int max_iter;

	cout << "          NEWTON-RAPHSON METHOD\n";
	cout << "============================================\n";
	cout << "Enter initial guess: "; cin >> x;
	cout << "Enter tolerance: "; cin >> tol;
	cout << "Enter maximum iterations: "; cin >> max_iter;

	cout << "\n";
	cout << "---------------------------------------------------------------\n";
	cout << setw(5)  << "Iter"
		<< setw(15) << "x"
		<< setw(15) << "f(x)"
		<< setw(15) << "f'(x)"
		<< setw(15) << "x_new" << "\n";
	cout << "---------------------------------------------------------------\n";

	for (int i = 1; i <= max_iter; i++) {
		double fx = f(x);
		double dfx = df(x);

		if (dfx == 0) {
			cout << "\nError: Derivative is zero.\n";
			return 0;
		}

		double x_new = x - fx / dfx;

		cout << fixed << setprecision(8);
		cout << setw(5)  << i
			<< setw(15) << x
			<< setw(15) << fx
			<< setw(15) << dfx
			<< setw(15) << x_new <<'\n';

		if (abs(f(x_new)) < tol) {
			cout << "---------------------------------------------------------------\n";
			cout << "\nRoot = " << x_new << '\n';
			cout << "f(root) = " << f(x_new) << '\n';
			cout << "Iterations = " << i << '\n';
			return 0;
		}

		x = x_new;
	}

	cout << "---------------------------------------------------------------\n";
	cout << "\nMaximum iterations reached.\n";
	cout << "Approximate root = " << x << '\n';

	return 0;
}