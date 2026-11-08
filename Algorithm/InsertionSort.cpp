#include <bits/stdc++.h>
using namespace std;


void InsertionSort (vector<int>& v, int n) {
	for (int i = 1; i < n; i++) {
		int curr = v[i];
		int pre = i-1;
		while (pre >= 0 && v[pre] > curr) {
			v[pre+1] = v[pre];
			pre--;
		}
		v[pre+1] = curr;
	}
}

int main () {
	int n; cin >> n;
	vector<int> v(n);
	for (auto& x: v) cin >> x;

	InsertionSort (v, n);

	for (auto x: v) cout << x << " ";
}