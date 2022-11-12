#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define cpresent(c,x) ((c).find(x) != (c).end()) 
#define vpresent(c,x) (find(all(c),x) != (c).end())
#define endl '\n'
#define ff first
#define ss second
#ifdef LOCAL
#include "/home/iggaboi/Desktop/CP/debug.h"
#else
#define debug(Args...)
#endif
// using pii = pair<int, int>;
using ll = long long;
using namespace __gnu_pbds;
using namespace std;
template<class T>
using indexed_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;

void shit() {
	int n; cin >> n;
    cout << (1000 - n%1000)%1000 << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(false),cin.tie(nullptr);
	// int t; cin >> t;
	// while(t--)
		shit();
	return 0;
}

