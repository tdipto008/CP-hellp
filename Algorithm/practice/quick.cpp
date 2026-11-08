#include <bits/stdc++.h>
using namespace std;

int part (vector<int>& v, int st, int end) {
	int pivot = end;
	int indx = st -1;
	for (int i = st; i < end; i++) {
		if (v[i] < v[pivot]) {
			indx++;
			swap(v[indx], v[i]);
		}
	}
	indx++;
	swap(v[indx], v[pivot]);
	return indx;
}

void quick (vector<int>& v, int st, int end) {
	if (st < end) {
		int pivindx = part(v, st, end);

		quick(v, st, pivindx-1);
		quick(v, pivindx+1, end);

	}
}

int main () {
	int n; cin >> n;
	vector<int> v(n);
	for (auto& x: v) cin >> x;
	quick (v, 0, n-1);
	for (auto& x: v) cout << x << " ";
}