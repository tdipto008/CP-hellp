/**
 * Description: just DFS
 * Time: O(N+M)
 * Source: Own
 */

struct DFS {
	int N;
	vector<vector<int>> adj;
	vector<bool> visited;
	DFS(int _N) {
		N = _N;
		adj.resize(N); visited.resize(N);
	}
	void inp(int u, int v) {
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	void dfs(int u) {
		visited[u] = true;
		for (auto& v: adj[u]) {
			if (!visited[v]) dfs(v);
		}
	}
};