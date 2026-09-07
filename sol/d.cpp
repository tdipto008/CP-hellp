#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../dbg_lib/debug.h"
#else
#define dbg(...)
#endif

#define endl "\n"
#define ll int64_t

int N;
vector<ll> tree;
 
void init (int n) {
	N = 1;
	while (N < n) N *= 2;
	tree.resize(2*N, INT_MAX);
}
 
void build (vector<int>& vec) {
	for (int i = 0; i < (int)vec.size(); i++) {
		tree[i + N] = vec[i];
	}
	
	for (int i = N-1; i > 0; i--) {
		tree[i] = min(tree[i*2], tree[i*2 + 1]);
	}
}

void update (int k, int val) {
	tree[k+=N] = val;
 
	for (int i = k/2; i > 0; i /= 2) {
		tree[i] = min(tree[i*2], tree[i*2 + 1]);
	}
}
 
ll query (int L, int R, int parent = 1, int lp = 0, int rp = N-1) {
	
	if (rp < L || lp > R) return INT_MAX;

	if (L <= lp && R >= rp) return tree[parent];

	int mid = (lp + rp) / 2;
 
	return (min(query(L, R, parent*2, lp, mid), query(L, R, (parent*2) + 1, mid+1, rp)));
}


void solve() {
	int n, q; cin >> n >> q;
	vector<int> vec(n);
	
	for (auto& x : vec) cin >> x;

	init(n);
	build(vec);

	while (q--) {
		int a, b; cin >> a >> b; a--, b--;
		cout << query(a, b) << endl;
	}
}

int32_t main () {
	 cin.tie(0)->sync_with_stdio(0);
	 solve();
}