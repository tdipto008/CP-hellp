#include <bits/stdc++.h>
using namespace std;

void selection (vector<int>& v, int n) {
	for (int i = 0; i < n; i++) {
		int minindx = i;
		for (int j = i+1; j < n; j++) {
			if (v[j] < v[minindx]) {
				minindx = j;
			}
		}
		swap (v[minindx], v[i]);
	}
}

int main () {
	int n; cin >> n;
	vector<int> v(n);
	for (auto& x: v) cin >> x;
	selection(v, n);
	for (auto& x: v) cout << x << " ";
}