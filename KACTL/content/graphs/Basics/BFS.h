struct BFS {
	int N;
	vector<int> dist;
	vector<vector<int>> adj;
	BFS(int _N) {
		N = _N;
		dist.resize(N, -1); adj.resize(N);
	}
	void ae(int u, int v) {
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	void gen(int st) {
		dist[st] = 0;
		queue<int> quu; quu.push(st);
		while (quu.size()) {
			int u = quu.front(); quu.pop();
			for (auto& v: adj[u]) if (dist[v] == -1) {
				dist[v] = dist[u] + 1;
				quu.push(v);
			}
		}
	}
};