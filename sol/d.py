#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../dbg_lib/debug.h"
#else
#define dbg(...)
#endif
#define endl "\n"

void solve (int TT) {
	int n, k; cin >> n >> k;
	map<int, int> freq;
	for (int i = 0 ; i < n; i++) {
		int _; cin >> _;
		freq[_]++;
	}

	int cnt = 0;
	int m = 0;
	for (int i = 0; i < n; i++) {
		cnt += freq[i];
		if (freq[i] == 0 || cnt < k) break;

		cnt -= k;
		freq[i]--;
		m++;
	}
	cout << m << endl;
}

int32_t main () {
	cin.tie(0)->sync_with_stdio(0);
	#ifdef FELIX
		auto _clock_start = chrono::high_resolution_clock::now(); 
	#endif
 
	int TT = 1;
	cin >> TT;
	while(TT--){solve(TT);}

	#ifdef FELIX
		cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
		chrono::high_resolution_clock::now()
		- _clock_start).count() << "ms." << endl;
	 #endif
}