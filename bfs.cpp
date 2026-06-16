#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...)
#endif

#define endl "\n"
#define ll int64_t

vector<vector<int>> adj;
vector<bool> visited;

void bfs (int src) {
	queue<int> qu;
	qu.push(src);
	visited[src] = true;
	while (!qu.empty()) {
		int u = qu.front();
		for (auto& v: adj[u]) {
			if (visited[v]) continue;
			qu.push(v);
			visited[v] = true;
		}
		qu.pop();
	}
}

void solve () {
	int n, m; cin >> n >> m;
	adj.resize(n);
	visited.resize(n, false);

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b; a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<int> vis;
	for (int i = 0; i <n; i++) {
		if (!visited[i]) {
			vis.push_back(i);
			bfs(i);
		}
	}
}

int32_t main () {
   cin.tie(0)->sync_with_stdio(0);
   solve();
}