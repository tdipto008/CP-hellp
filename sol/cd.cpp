#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../dbg_lib/debug.h"
#else
#define dbg(...)
#endif

#define endl "\n"

void dfs(int u) {
	vis[u] = 1;
	// 1. first visit time do
	for (auto& v: adj[u]) {
		if (!vis[v]) {
			// 2. do some thing in child
			dfs(v);
			// 3. child info to parent
		}
	}
	// 4. when leaving the node
}

void bfs(int src) {
	vector<bool> vis(n, false);
	queue<int> q;

	q.push(src);
	vis[src] = true;

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (auto& v: adj[u]) {
			if (!vis[v]) {
				vis[v] = true;
				dist[v] = dist[u] + 1;
				q.push(v); // bfs call
			}
		}
	}
}

//dsu
struct dsu {
	vector<set<int>> _sets(n);
	for (int i = 0; i < n; i++) {
		_sets[i].insert(i);
	}



};

void solve (int TT) {
	int n, m; cin >> n >> m;
	vector<vector<int>> adj;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
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