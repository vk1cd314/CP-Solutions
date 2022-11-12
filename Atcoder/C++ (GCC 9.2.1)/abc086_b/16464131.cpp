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
typedef long long ll;
typedef long double ld;
#define endl '\n'

int main() {
    cin.tie(0)->sync_with_stdio(0), cin.exceptions(cin.failbit);
#ifdef BOI
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int a, b; cin >> a >> b;
    int x = log10(b) + 1;
    a *= (int) pow(10, x);
    a += b;
    int temp = sqrt(a);
    if (temp * temp == a) {
        cout << "Yes";
    } else cout << "No";
}
