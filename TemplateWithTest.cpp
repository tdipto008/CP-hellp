#include <bits/stdc++.h>
using namespace std;

#ifdef dipto_008
#include "../dbg_lib/debug.h"
#else
#define dbg(...)
#endif

#define endl "\n"

void AYE_MAIN (int TT) {
	
}

int32_t main () {
	cin.tie(0)->sync_with_stdio(0);
	#ifdef dipto_008
		auto _clock_start = chrono::high_resolution_clock::now(); 
	#endif
 
	int DIPTO; cin >> DIPTO;
	for (int TT = 1; TT <= DIPTO; TT++) {
		AYE_MAIN (TT);
	}

	#ifdef dipto_008
		cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
		chrono::high_resolution_clock::now()
		- _clock_start).count() << "ms." << endl;
	 #endif
}