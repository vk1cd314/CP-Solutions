// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#ifdef BOI
#include "debug.h"
#else
#define debug(args...)
#endif
#define endl '\n'
using ll = long long;
using namespace std;

const int maxn = 1e3 + 69;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
#ifdef BOI
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ll n, d; cin >> n >> d;
    int cnt = 0;
    for(ll i = 0, x, y; i < n; ++i) {
        cin >> x >> y;
        if(x * x + y * y <= d * d) ++cnt;
    }
    cout << cnt;
    return 0;
}
