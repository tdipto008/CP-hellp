#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...)
#endif

#define endl "\n"
#define ll int64_t

vector<vector<int>> node;
vector<bool> visited;
void dfs (int u) {
	visited[u] = true;

	for (auto& v: node[u]) {
		if (visited[v]) continue;
		dfs(v);
	}
}

void solve () {
	int n, m; cin >> n >> m;
	node.resize(n);
	visited.resize(n, false);

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v; u--, v--;
		node[u].push_back(v);
		node[v].push_back(u);
	}
	vector<int> vis;
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			vis.push_back(i+1);
		}
	}
	cout << vis.size() << endl;
	for (auto i : vis) cout << i << " ";
}

int32_t main () {
	cin.tie(0)->sync_with_stdio(0);
	solve();
}