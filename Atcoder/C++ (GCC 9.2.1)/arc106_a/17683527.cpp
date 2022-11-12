#include <bits/stdc++.h>

using namespace std;

#ifdef BOI
#include "debug.h"
#else
#define debug(args...)
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
using pii = pair <int, int>;
using pli = pair <ll, int>;
using pll = pair <ll, ll>;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

const ll INF = (ll)1e18 + 69;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n; cin >> n;

    vector <ll> pow3, pow5;

    ll num = 3;
    while (num < INF) {
        pow3.pb(num);
        num *= 3;
    }

    num = 5;
    while (num < INF) {
        pow5.pb(num);
        num *= 5;
    }

    pii ans;
    bool ok = false;
    for (int i = 0; i < (int) pow3.size(); ++i) {
        for (int j = 0; j < (int) pow5.size(); ++j) {
            if (pow3[i] + pow5[j] == n) {
                ok = true;
                ans = {i + 1, j + 1};
            }
        }
        if (ok) break;
    }

    if (ok) cout << ans.fi << ' ' << ans.se;
    else cout << "-1\n";
}