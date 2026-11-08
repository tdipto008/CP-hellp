#include <bits/stdc++.h>
using namespace std;

void merge (vector<int>& v, int st, int end, int mid) {
	int n1 = mid - st + 1, n2 = end - mid;
	vector<int> left, right;
	for (int i = st; i <= mid; i++) {
		left.push_back(v[i]);
	}
	for (int i = mid+1; i <= end; i++) {
		right.push_back(v[i]);
	}

	int i = 0, j = 0, k =st;
	while (i < n1 && j < n2) {
		if (left[i] < right[j]) {
			v[k] = left[i];
			k++, i++;
		} else {
			v[k] = right[j];
			k++, j++;
		}
	}
	while (i < n1) {
		v[k] = left[i];
		k++, i++;
	}
	while (j < n2) {
		v[k] = right[j];
		k++, j++;
	}
}

void mergeSort (vector<int>& v, int st, int end) {
	if (st < end) {
		int mid = (st+end) / 2;

		mergeSort (v, st, mid);
		mergeSort (v, mid+1, end);

		merge (v, st, end, mid);
	}
}

int main () {
	int n; cin >> n;
	vector<int> v(n);
	for (auto& x: v) cin >> x;
	mergeSort (v, 0, n-1);
	for (auto& x: v) cout << x << " ";
}