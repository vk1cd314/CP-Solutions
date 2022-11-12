#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif

using namespace std;

const int N = 1e5 + 6 + 9;
int dp[N][3], n, a[N][3];

int rec(int i, int x) {
	if (i == n) return 0;

	int &ret = dp[i][x];
	if (~ret) return ret;
	
	if (x == 0) {
		ret = a[i][x] + max(rec(i + 1, 1), rec(i + 1, 2));
	}
	if (x == 1) {
		ret = a[i][x] + max(rec(i + 1, 0), rec(i + 1, 2));
	} 
	if (x == 2) {
		ret = a[i][x] + max(rec(i + 1, 1), rec(i + 1, 0));
	}

	return ret;
}

int main() {
	#ifdef Icry
		auto begin = std::chrono::high_resolution_clock::now();
	#endif
	ios_base :: sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i][0] >> a[i][1] >> a[i][2];
	memset(dp, -1, sizeof dp);

	cout << max({rec(0, 0), rec(0, 1), rec(0, 2)}) << '\n';


	#ifdef Icry
		auto end = std::chrono::high_resolution_clock::now();
		cerr << setprecision(4) << fixed;
		cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
	#endif
}