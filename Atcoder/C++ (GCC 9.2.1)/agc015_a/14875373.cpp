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

void shit() {
    ll n, a, b; cin >> n >> a >> b;
    if(a > b) {
		cout << 0 << endl;
		return;
	}
	if(n == 1 and a != b) {
		cout << 0 << endl;
		return;
	}
	if(n == 1) {
		cout << 1 << endl;
		return;
	}
	if(a == b) {
		cout << 1 << endl;
		return;
	}
	cout << (n - 2)*(b - a) + 1 << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(false),cin.tie(nullptr);
	// int t; cin >> t;
	// while(t--)
		shit();
	return 0;
}
