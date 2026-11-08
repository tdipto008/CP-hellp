#include <bits/stdc++.h>
using namespace std;



int main () {
	int n; cin >> n;
	vector<int> v(n);
	for (auto& x: v) cin >> x;

	int tr; cin >> tr;
	
	int l = 0, r = n;
	while (l <= r) {
		int mid = (l+r+1)/2;

		if (v[mid] == tr) {
			cout << "fount at " << mid << endl;
			return 0;
		} else if (v[mid] > tr) {
			r = mid-1;
		} else {
			l = mid+1;
		}
	}
	cout << "Not found" << endl;
}