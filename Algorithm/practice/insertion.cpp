#include <bits/stdc++.h>
using namespace std;

void insertion (vector<int>& v, int n) {
	for (int i = 1; i < n; i++) {
		int pre = i-1;
		int cur = v[i];
		while (pre >= 0 && v[pre] > cur) {
			v[pre+1] = v[pre];
			pre--;
		}
		v[pre+1] = cur;
	}
}

int main () {
	int n; cin >> n;
	vector<int> v(n);
	for (auto& x: v) cin >> x;
	insertion (v, n);
	for (auto& x: v) cout << x << " ";
}