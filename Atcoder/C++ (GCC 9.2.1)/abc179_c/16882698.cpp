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
    long long n; cin >> n;

    long long ans = 0;

    for (long long i = 1; i < n; ++i) {
        ans += ((n - 1) / i);
    }

    cout << ans;
}
