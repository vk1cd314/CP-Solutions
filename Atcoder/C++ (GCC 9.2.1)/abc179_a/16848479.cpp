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
    string s; cin >> s;
    char x = s.back();
    if (x == 's') {
        s += "es";
    } else {
        s += "s";
    }
    cout << s;
}
