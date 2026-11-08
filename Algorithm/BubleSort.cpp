#include <bits/stdc++.h>
using namespace std;

void BubleSort (vector<int>& v, int n) {
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n-i-1; j++) {
			if (v[j+1] < v[j]) swap(v[j+1], v[j]);
		}
	}
}

int main () {
	int n; cin >> n;
	vector<int> v(n);
	for (auto& x: v) cin >> x;

	BubleSort(v, n);

	for (auto x: v) cout << x << " ";
}