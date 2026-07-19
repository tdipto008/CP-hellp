#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../dbg_lib/debug.h"
#else
#define dbg(...)
#endif

#define endl "\n"
#define ll int64_t

const int N = 2e5 + 1;
vector<int> fact2(N, 0);
void fc () {
	for (int i = 1; i < N; i++) {
		int j = i;
		while (j%2 == 0) {
			j /= 2;
			fact2[i]++;
		}
	}
}

void solve () {
	int n; cin >> n;
	vector<int> v(n);
	for (auto& x: v) cin >> x;
	int cnt2 = 0;
	vector<int> _2(n, 0);
	for (int i = 0; i < n; i++) {
		if (v[i] == 0) continue;
		while (v[i] % 2 == 0) {
			_2[i]++;
			v[i] /= 2;
		}
		cnt2 += _2[i];
	}
	if (cnt2 >= n) {
		cout << 0 << endl;
		return;
	}

	vector<int> a;
	for (int i = 1; i <= n; i++) {
		a.push_back(fact2[i]);
	}
	sort(rbegin(a), rend(a));
	int cntop = 0;
	for (int i = 0; i < n; i++) {
		cnt2 += a[i]; cntop++;
		if (cnt2 >= n) {
			cout << cntop << endl;
			return;
		}
	}
	cout << -1 << endl;

}

int32_t main () {
		cin.tie(0)->sync_with_stdio(0);
		fc();
		int TT; cin >> TT;
		while (TT--) {solve();}
}