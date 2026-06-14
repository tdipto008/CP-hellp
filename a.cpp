#include <bits/stdc++.h>
using namespace std;

int main () {
	i#include <bits/stdc++.h>
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

void dfs (int u) {
	visited[u] = true;
	for (auto v : adj[u]) {
		if (visited[v]) continue;
		dfs(v);
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
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			vis.push_back(i);
			dfs(i);
		}
	}

	cout << vis.size()-1 << endl;
	for (int i = 1; i < vis.size(); i++) {
		cout << vis[i-1] << " " << vis[i] << endl;
	}
}

int32_t main () {
   cin.tie(0)->sync_with_stdio(0);
   solve();
}
	cout << n << endl;
}

//n+(n^2)+n+m = 2n+(n^2)+m
//9+9 =18 ... 10.. 100