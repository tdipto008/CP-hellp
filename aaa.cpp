#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...)
#endif

template<int N> struct Sieve { 
    bitset<N> is_prime; vector<int> primes;
    Sieve() {
        is_prime.set(); is_prime[0] = is_prime[1] = 0;
        for (int i = 4; i < N; i += 2) is_prime[i] = 0;
        for (int i = 3; i*i < N; i += 2) if (is_prime[i])
            for (int j = i*i; j < N; j += i*2) is_prime[j] = 0;
        for (int i = 0; i < N; i++) if (is_prime[i]) primes.push_back(i);
    }
};
const int N = 1e7+1;
Sieve<N> S;
int cntPri[N], DP[N];

void solve() {
    int n; cin >> n;
    cout << DP[n] << "\n";
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    cntPri[1] = 1;
    for (int i = 2; i < N; i++) {
        cntPri[i] = cntPri[i-1] + S.is_prime[i];
    }

    DP[1] = DP[2] = DP[3] = 1;
    for (int i = 4; i < N; i++) {
        DP[i] = DP[i-cntPri[i]] + 1;
    }

    int tc = 0;
    int Q; cin >> Q;
    while (Q--) {
        cout << "Case " << ++tc << ": ";
        solve(); }
}