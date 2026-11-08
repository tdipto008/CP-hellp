#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../dbg_lib/debug.h"
#else
#define dbg(...)
#endif

#define endl "\n"
#define int int64_t
int n, w;
vector<vector<int>> dp(n);
vector<int> weight, profit;

int calc (int i, int rem) {
	if (i == 0 || rem == 0) return 0;
	if (dp[i][rem] != -1) return dp[i][rem];

	int ans = calc(i-1, rem);
	if (weight[i-1] <= rem) {
		ans = max(ans, profit[i-1] + calc(i-1, rem-weight[i-1]));
	}
	return dp[i][rem] = ans;
}

void solve (int TT) {
	cin >> n >> w;
	weight.resize(n), profit.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> weight[i] >> profit[i];
	}
	dp.assign(n+1, vector<int> (w+1, -1));
	cout << calc(n, w) << endl;
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