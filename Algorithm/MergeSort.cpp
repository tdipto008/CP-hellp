#include <bits/stdc++.h>
using namespace std;

void Merge (vector<int>& v, int st, int end, int mid) {
	vector<int> v1, v2;
	for (int i = st; i <= mid; i++) {
		v1.push_back(v[i]);
	}
	for (int i = mid+1; i <= end; i++) {
		v2.push_back(v[i]);
	}

	int i = 0, j = 0, k = st;
	while (i < (mid-st+1) && j < (end-mid)) {
		if (v1[i] <= v2[j]) {
			v[k] = v1[i];
			k++, i++;
		} else {
			v[k] = v2[j];
			k++, j++;
		}
	}

	while (i < (mid-st+1)) {
		v[k] = v1[i];
		k++, i++;
	}

	while (j < end-mid) {
		v[k] = v2[j];
		k++, j++;
	}
}

void MergeSort (vector<int>& v, int st, int end) {
	if (st < end) {
		int mid = (st + end) / 2;

		MergeSort(v, st, mid);
		MergeSort(v, mid+1, end);

		Merge (v, st, end, mid);
	}
}

int main () {
	int n; cin >> n;
	vector<int> v(n);
	for (auto& x: v) cin >> x;

	MergeSort (v, 0, n-1);

	for (auto x: v) cout << x << " ";
}