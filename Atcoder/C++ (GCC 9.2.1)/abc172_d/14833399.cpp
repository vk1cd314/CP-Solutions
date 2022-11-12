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

ll n;

void shit() {
    cin >> n;
    ll ans = 0;
    // a(n) = Sum_{m=1..floor(sqrt(n))} m*(m+floor(n/m))*(floor(n/m)+1-m)
    for(ll i = 1; i <= sqrt(n); ++i) {
        ans += i*(i + (n/i))*(n/i + 1 - i);
    }
    n = sqrt(n);
    ll extra = n;
    extra *= (n + 1);
    extra *= (2*n + 1);
    extra /= 6;//n*(n+1)*(2*n+1)/6
    ans -= extra;
    cout << ans << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(false),cin.tie(nullptr);
	// int t; cin >> t;
	// while(t--)
		shit();
	return 0;
}
