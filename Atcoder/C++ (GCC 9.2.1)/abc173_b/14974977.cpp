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
using ll = long long;
using namespace __gnu_pbds;
using namespace std;
template<class T>
using indexed_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;

void shit() {
	int n; cin >> n;
    map<string, int> mp;
    for(int i = 0; i < n; ++i) {
        string s; cin >> s;
        if(s == "AC") ++mp["AC"];
        if(s == "WA") ++mp["WA"];
        if(s == "TLE") ++mp["TLE"];
        if(s == "RE") ++mp["RE"];
    }
    cout << "AC x " << mp["AC"] << endl;
    cout << "WA x " << mp["WA"] << endl;
    cout << "TLE x " << mp["TLE"] << endl;
    cout << "RE x " << mp["RE"] << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(false),cin.tie(nullptr);
	// int t; cin >> t;
	// while(t--)
		shit();
	return 0;
}

