#include "bits/stdc++.h"
#define int long long
#define all(c) (c).begin(), (c).end()
#define cpresent(c,x) ((c).find(x) != (c).end()) // present in container?
#define vpresent(c,x) (find(all(c),x) != (c).end()) // present in vector?
#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr), cout.tie(nullptr)
#define endl '\n'
using namespace std;

int n;
const int xd = 1e18;

void solve(){   
    int ans = 1, zero = 0;
    cin >> n;
    vector<int> ara(n);
    for(int i = 0; i < n; ++i){
        cin >> ara[i];
        if(ara[i] == 0)
            zero++;
    }

    if(zero){
        cout << 0 << endl;
        return;
    }
    
    for(int i = 0; i < n; ++i){
        if(ara[i] <=1000000000000000000/ ans ){
            ans *= ara[i];
        }else{
            cout << -1 << endl;
            return;
        }
    }
    cout << ans << endl;
}
signed main(){
	fastio;
	// int t; cin >> t;
	// while(t--)
		solve();
	return 0;
}
