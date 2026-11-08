#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, k; cin >> n >> k;

	vector<int> a(n);
	for(auto& x: a) cin >> x;
	
	int64_t ans = 0;
	int nibo = n-k+1, unibo = n-nibo;
	for (int i = 0; i < min(nibo, unibo); i++) {
		ans += max(a[i], a[n-i-1]);
	}
	for (int i = unibo; i < nibo; i++) {
		ans += a[i];
	}
	cout << ans << "\n";
}

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);

	int Q; cin >> Q;
	while (Q--) { solve(); }
}