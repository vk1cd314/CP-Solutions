#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll k , n ; cin >> k >> n;

    ll a[n];

    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    ll ma = 0;
    ll prev = 0;
    for (ll i = 0; i < n; i++) {
        ma = max(ma, abs(prev - a[i]));
        prev = a[i];
    }

    ma = max(ma, k - a[n-1] + a[0]);

    ll ans = k - ma;
    cout << ans << endl;

    return 0;
}
