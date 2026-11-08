#include <bits/stdc++.h>
using namespace std;

double f(double x) { return 1 / (1 + x * x); }

int main() {
	double a, b;
	int n;
	cout << "Enter lower limit (a): "; cin >> a;
	cout << "Enter upper limit (b): "; cin >> b;
	cout << "Enter number of intervals (even): "; cin >> n;
	if (n % 2 != 0) {
		cout << "\nError: Number of intervals must be even.\n";
		return 0;
	}
	double h = (b - a) / n;
	double sum = f(a) + f(b);
	for (int i = 1; i < n; i++) {
		double x = a + i * h;
		double fx = f(x);
		int multiplier = (i % 2 == 0) ? 2 : 4;

		double term = multiplier * fx;
		sum += term;
	}
	double result = (h / 3) * sum;
	cout << "\nIntegral = " << result << '\n';
	return 0;
}