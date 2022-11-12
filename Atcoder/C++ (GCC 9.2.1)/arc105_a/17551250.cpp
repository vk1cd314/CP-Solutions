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

const ll INF = (ll)2e9 + 69;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    vector <ll> a(4); cin >> a[0] >> a[1] >> a[2] >> a[3];
    
    bool ok = false;
    for (int i = 0; i < 16; ++i) {
        ll sum = accumulate(all(a), 0);
        ll sum1 = 0;
        for (int j = 0; j < 4; ++j) {
            if (i & (1 << j)) sum1 += a[j];
        }
        sum -= sum1;
        if (sum == sum1) {
            ok = true;
            break;
        }
    }
    
    cout << (ok ? "Yes" : "No");
}