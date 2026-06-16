#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...)
#endif

#define endl "\n"
#define ll int64_t


int32_t main () {
	cin.tie(0)->sync_with_stdio(0);

	string s;
	while (cin >> s) {
		map<char, int> mp;
		for (int i = 0; i < s.size(); i++) {
			mp[s[i]]++;
		}

		int mx = 0;
		for (auto i : mp) {
			mx = max(i.second, mx);
		}

		if (mx == s.size()) {
			cout << "Done!" << endl;
		} else {
			cout << s.size() - mx << endl;
		}
	}
}