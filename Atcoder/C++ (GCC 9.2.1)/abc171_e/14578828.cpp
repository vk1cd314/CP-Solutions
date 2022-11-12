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

int n;

void solve(){
    cin >> n;
    vector<int> xors(n);
    int xx = 0;
    for(int i = 0; i < n; ++i){
        cin >> xors[i];
        xx ^= xors[i];
    }
    for(int i = 0; i < n; ++i)
        xors[i] = xx ^ xors[i];
    
    for(int i = 0; i < n; ++i)
        cout << xors[i] << " ";
}

int32_t main(){
	ios_base::sync_with_stdio(false),cin.tie(nullptr);
	// int t; cin >> t;
	// while(t--)
		solve();
	return 0;
}
