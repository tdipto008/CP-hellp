#include <bits/stdc++.h>
using namespace std;

#define INPUT "../sol/input.txt"
#define OUTPUT "../sol/output.txt"
#define ERROR "../sol/error.txt"

struct Debug { 
	Debug() {freopen(INPUT,"r",stdin); freopen(OUTPUT,"w",stdout); freopen(ERROR,"w",stderr);}
};
Debug debug;
template<class T> void print(T x) {cerr << x;}
template<class T> void print(vector<T> v) {cerr << "[ ";for(auto x:v) cerr << x << " "; cerr << "]";}
#define dbg(x) cerr << #x << " = "; print(x); cerr << '\n';
