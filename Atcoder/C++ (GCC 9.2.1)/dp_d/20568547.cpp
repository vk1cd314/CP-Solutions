#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif

using namespace std;

const int W = 1e5 + 6 + 9, N = 1e2 + 6 + 9;
int64_t F[W][N], w[N], val[N], n, ww;

int64_t rec(int64_t curr, int pos) {
	if (pos == n) return 0;

	int64_t &ret = F[curr][pos];
	if (~ret) return ret;

	if (curr + w[pos] <= ww) ret = val[pos] + rec(curr + w[pos], pos + 1);
	ret = max(ret, rec(curr, pos + 1));
	return ret;
}

int main() {
	#ifdef Icry
		auto begin = std::chrono::high_resolution_clock::now();
	#endif
	ios_base :: sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> ww;
	for (int i = 0; i < n; ++i) cin >> w[i] >> val[i];
	memset(F, -1, sizeof F);

	cout << rec(0, 0) << '\n';

	#ifdef Icry
		auto end = std::chrono::high_resolution_clock::now();
		cerr << setprecision(4) << fixed;
		cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
	#endif
}