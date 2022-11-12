// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;

#ifdef BOI
#include "debug.h"
#else
#define debug(args...)
#endif

#define all(x) begin(x), end(x)
#define sz(x) (int) x.size()
#define eps 1e-7
#define inf 0x3f3f3f3f
#define endl '\n'

int main() {
    cin.tie(0)->sync_with_stdio(0), cin.exceptions(cin.failbit);
    int n; cin >> n;
    vector<vector<int>> g(n, vector<int>(2, 0));
    for (auto& it : g) {
        cin >> it[0] >> it[1];
    }

    int ans = 0;
    for (int i = 0; i + 2 < n; ++i) {
        if (g[i][0] == g[i][1] && g[i + 1][0] == g[i + 1][1] && g[i + 2][0] == g[i + 2][1]) ++ans;
    }
    cout << (ans ? "Yes" : "No");
}
