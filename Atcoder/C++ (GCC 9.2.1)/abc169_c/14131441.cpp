#include "bits/stdc++.h"
#define int long long
#define all(c) (c).begin(), (c).end()
#define cpresent(c,x) ((c).find(x) != (c).end()) // present in container?
#define vpresent(c,x) (find(all(c),x) != (c).end()) // present in vector?
#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr), cout.tie(nullptr)
#define endl '\n'
using namespace std;

long double a, b;

void solve(){   
    cin >> a >> b;
    int ans = (int) a*(b*1000)/1000;
    printf("%lld",ans);
}
signed main(){
	fastio;
	// int t; cin >> t;
	// while(t--)
		solve();
	return 0;
}
