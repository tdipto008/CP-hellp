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
	int n, x, y, z; cin >> n >> x >> y >> z;
	int a = (n+x+y-1)/(x+y);
	int b;
	if (n <= z*x) {
		b=(n+x-1)/x;
		cout << min(a,((x+y-1)/x)) << endl;
	} else {
		n -= z*x;
		b = z+(n+(x+10*y)-1)/(x+10*y);
	}
}

int32_t main () {
	cin.tie(0)->sync_with_stdio(0);
	int TT; cin >> TT;
	while (TT--) {solve();}
}