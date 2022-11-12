#include "bits/stdc++.h"
#define int long long
#define all(c) (c).begin(), (c).end()
#define cpresent(c,x) ((c).find(x) != (c).end()) 
#define vpresent(c,x) (find(all(c),x) != (c).end())
#define endl '\n'
#ifdef LOCAL
#include "/home/iggaboi/Desktop/CP/debug.h"
#else
#define debug(x...)
#endif
using namespace std;

int n, k;

void solve(){
    cin >> n >> k;
    vector<int> ara(n);
    for(int& it : ara)
        cin >> it;
    sort(all(ara));
    int sum = 0;
    for(int i = 0; i < k; ++i)
        sum += ara[i];
    cout << sum << endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false),cin.tie(nullptr);
	// int t; cin >> t;
	// while(t--)
		solve();
	return 0;
}
