#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../dbg_lib/debug.h"
#else
#define dbg(...)
#endif

#define endl "\n"


struct DSU {
	// int sz, comp;
	vector<vector<int>> sets;
	vector<int> e, lazy, sum;
	DSU(int N) : lazy(N), sum(N) {
		e = vector<int>(N, -1);
		sets.resize(N);
		for (int i = 0; i < N; i++) {
			sets[i].push_back(i);
		}
	}
	
	int get(int u) { return e[u] < 0 ? u : e[u] = get(e[u]); }
	
	bool sameSet(int u, int v) { return get(u) == get(v); }
	
	int size(int u) { return -e[get(u)]; }
	
	bool unite(int u, int v) { // union by size
		u = get(u), v = get(v); if (u == v) return false;
		if (e[u] > e[v]) swap(u, v);
		for (auto& x: sets[v]) {
			sets[u].push_back(x);
			sum[x] += lazy[v] - lazy[u];
		}
		sets[v].clear();
		e[u] += e[v]; e[v] = u; 
		// sz = max(sz, -e[u]); comp--;
		return true;
	}
	int query (int u) {
		return sum[u]+lazy[get(u)];
	}
};

void solve (int TT) {
	int n, q; cin >> n >> q;
	DSU D(n);
	vector<int> points(n, 0);
	while (q--) {
		string op; cin >> op;
		if (op == "join") {
			int u, v; cin >> u >> v; u--, v--;
			D.unite(u, v);
		} else if (op == "add") {
			int u, v; cin >> u >> v; u--, v;
			int p = D.get(u);
			for (int i = 0; i < n; i++) {
				if (D.get(i) == p) points[i] += v;
			}
		} else {
			int u; cin >> u; u--;
			cout << points[u] << endl;
		}
	}

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