#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...)
#endif

#define endl "\n"
#define ll int64_t

void solve () {
	int n; cin >> n;
	string s; cin >> s;
	if (s[0] == s[n-1] && s[0]=='1') {
		cout << "YES" << endl;
		return;
	}
	int _111 = 0;
	for (int i = 0; i < n-2; i++) {
		if (s[i] == '1' && s[i+1] == '1' && s[i+2] == '1') _111++;
	}
	if (_111 >= 1) {
		cout << "YES" << endl;
		return;
	}

	int _11 = 0;
	for (int i = 0; i < n-1; i++) {
		if (s[i] == s[i+1] && s[i]=='1') {
			_11++;i++;
		}
	}
	if (_11 >= 2 || ((s[0]=='1' || s[n-1] == '1')&& _11 >= 1)) {
		cout << "YES" << endl;
		return;
	}
	cout << "NO" << endl;
}

int32_t main () {
	cin.tie(0)->sync_with_stdio(0);
	int TT; cin >> TT;
	while (TT--) {solve();}
}