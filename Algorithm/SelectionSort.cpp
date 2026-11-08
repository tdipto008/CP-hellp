#include <bits/stdc++.h>
using namespace std;

void SelectionSort (vector<int>& v, int n) {
	for (int i = 0; i < n-1; i++) {
		int indx = i;
		for (int j = i+1; j < n; j++) {
			if (v[j] < v[indx]) indx = j;
		}
		swap (v[i], v[indx]);
	}
}

int main () {
	int n; cin >> n;
	vector<int> v(n);
	for (auto& x: v) cin >> x;

	SelectionSort(v, n);

	for (auto x: v) cout << x << " ";
}