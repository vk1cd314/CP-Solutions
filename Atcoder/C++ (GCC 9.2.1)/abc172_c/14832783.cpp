#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define cpresent(c,x) ((c).find(x) != (c).end()) 
#define vpresent(c,x) (find(all(c),x) != (c).end())
#define endl '\n'
#ifdef LOCAL
#include "/home/iggaboi/Desktop/CP/debug.h"
#else
#define debug(Args...)
#endif
using ll = long long;
using namespace __gnu_pbds;
using namespace std;
template<class T>
using indexed_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k;

void shit() {
	cin >> n >> m >> k;
    vector<ll> a(n + 1), b(m + 1);
    a[0] = 0, b[0] = 0;
    for(ll i = 1; i <= n; ++i) {
        ll x; cin >> x;
        a[i] = a[i - 1] + x;
    }
    for(ll i = 1; i <= m; ++i) {
        ll x; cin >> x;
        b[i] = b[i - 1] + x;
    }
    ll ans = 0, cnt = m;
    debug(a, b);
    for(ll i = 0; i <= n; ++i) {
        if(a[i] > k) break;
        while(b[cnt] + a[i] > k) --cnt;
        ans = max(ans, i + cnt);
    }
    cout << ans << endl;

}

int32_t main() {
	ios_base::sync_with_stdio(false),cin.tie(nullptr);
	// int t; cin >> t;
	// while(t--)
		shit();
	return 0;
}
