#include <bits/stdc++.h>
using namespace std;

double f(double x) { return 1 / (1 + x * x); }

int main() {
	double a, b;
	int n;

	cout << "          SIMPSON'S 1/3 RULE\n";
	cout << "============================================\n";
	cout << "Enter lower limit (a): "; cin >> a;
	cout << "Enter upper limit (b): "; cin >> b;
	cout << "Enter number of intervals (even): "; cin >> n;

	if (n % 2 != 0) {
		cout << "\nError: Number of intervals must be even.\n";
		return 0;
	}

	double h = (b - a) / n;
	double sum = f(a) + f(b);

	cout << "\n";
	cout << "---------------------------------------------------------------\n";
	cout << setw(5)  << "i"
		<< setw(15) << "x"
		<< setw(15) << "f(x)"
		<< setw(15) << "Multiplier"
		<< setw(15) << "Term" << '\n';
	cout << "---------------------------------------------------------------\n";

	cout << fixed << setprecision(8);

	cout << setw(5) << 0
		<< setw(15) << a
		<< setw(15) << f(a)
		<< setw(15) << 1
		<< setw(15) << f(a) << '\n';

	for (int i = 1; i < n; i++) {
		double x = a + i * h;
		double fx = f(x);
		int multiplier = (i % 2 == 0) ? 2 : 4;

		double term = multiplier * fx;
		sum += term;

		cout << setw(5) << i
			<< setw(15) << x
			<< setw(15) << fx
			<< setw(15) << multiplier
			<< setw(15) << term << '\n';
	}

	cout << setw(5) << n
		<< setw(15) << b
		<< setw(15) << f(b)
		<< setw(15) << 1
		<< setw(15) << f(b) << '\n';

	double result = (h / 3) * sum;

	cout << "---------------------------------------------------------------\n";
	cout << "\nIntegral = " << result << '\n';

	return 0;
}