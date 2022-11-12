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

int sx, sy, tx, ty;

void solve(){
    cin >> sx >> sy >> tx >> ty;
    for(int i = 0; i < ty - sy; ++i) cout << 'U';
    for(int i = 0; i < tx - sx; ++i) cout << 'R';
    for(int i = 0; i < ty - sy; ++i) cout << 'D';
    for(int i = 0; i < tx - sx; ++i) cout << 'L';
    cout << 'L';
    for(int i = 0; i <= ty - sy; ++i) cout << 'U';
    for(int i = 0; i <= tx - sx; ++i) cout << 'R';
    cout << 'D';
    cout << 'R';
    for(int i = 0; i <= ty - sy; ++i) cout << 'D';
    for(int i = 0; i <= tx - sx; ++i) cout << 'L';
    cout << 'U';
}

int32_t main(){
	ios_base::sync_with_stdio(false),cin.tie(nullptr);
	// int t; cin >> t;
	// while(t--)
		solve();
	return 0;
}
