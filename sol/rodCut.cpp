
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../dbg_lib/debug.h"
#else
#define dbg(...)
#endif

#define endl "\n"

vector<int> dp;

int calc (vector<int>& price, int ln) {
	if (ln == 0) return 0;
	if (dp[ln] != -1) return dp[ln];

	int ans = 0;
	for (int cut = 1; cut <= ln; cut++) {
		ans = max(ans, price[cut]+calc(price, ln-cut));
	}
	return dp[ln] = ans;
}

void solve (int TT) {
	int n; cin >> n;
	vector<int> price(n+1);
	dp.assign(n+1, -1);
	for (int i = 1; i <= n; i++) cin >> price[i];
	cout << calc(price, n) << endl;
}

int32_t main () {
	cin.tie(0)->sync_with_stdio(0);
	#ifdef FELIX
		auto _clock_start = chrono::high_resolution_clock::now(); 
	#endif
 
	int TT = 1;
	//cin >> TT;
	while(TT--){solve(TT);}

	#ifdef FELIX
		cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
		chrono::high_resolution_clock::now()
		- _clock_start).count() << "ms." << endl;
	#endif
}