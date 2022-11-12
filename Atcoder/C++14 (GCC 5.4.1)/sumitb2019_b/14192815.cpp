#include "bits/stdc++.h"
#define int long long
#define eps 1e-9
#define all(c) (c).begin(), (c).end()
#define cpresent(c,x) ((c).find(x) != (c).end()) // present in container?
#define vpresent(c,x) (find(all(c),x) != (c).end()) // present in vector?
#define endl '\n'
using namespace std;

double n;

void solve(){
    cin >> n;
    int ans = -69;
    int hmm;
    for(double i = 1; i <= n; ++i){
        if(i*1.08 - (int)i*1.08 >= 0.5)
            hmm = ceil(i*1.08);
        else
            hmm = floor(i*1.08);
        if(hmm ==(int) n)
            ans = (int)i;
    }
    if(ans == -69){
        cout << ":(" << endl;
        return;
    }
    cout << ans << endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	// int t; cin >> t;
	// while(t--)
		solve();
	return 0;
}
