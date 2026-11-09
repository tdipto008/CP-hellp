#include <bits/stdc++.h>
using namespace std;

#ifdef dipto_008
#include "../dbg_lib/debug.h"
#else
#define dbg(...)
#endif

#define endl "\n"

void AYE_MAIN (int TT) {
	cout << "d" << endl;
}

int32_t main () {
	cin.tie(0)->sync_with_stdio(0);
	#ifdef dipto_008
		auto _clock_start = chrono::high_resolution_clock::now(); 
	#endif
 
	int TT; cin >> TT;
	for (int QQ = 1; QQ <= TT; QQ++) AYE_MAIN (QQ);

	#ifdef dipto_008
		cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
		chrono::high_resolution_clock::now()
		- _clock_start).count() << "ms." << endl;
	 #endif
}