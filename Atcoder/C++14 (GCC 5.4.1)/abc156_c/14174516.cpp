#include "bits/stdc++.h"
#define int long long
#define all(c) (c).begin(), (c).end()
#define cpresent(c,x) ((c).find(x) != (c).end()) // present in container?
#define vpresent(c,x) (find(all(c),x) != (c).end()) // present in vector?
#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr), cout.tie(nullptr)
#define endl '\n'
using namespace std;

int n;

void solve(){   
    cin >> n; 
    int low = 169, high = -69;
    vector<int> ara(n);
    for(int i = 0; i < n; ++i){
        cin >> ara[i];
        low = min(ara[i], low);
        high = max(ara[i], high);
    }
    int out = 1e9 + 69;
    for(int i = low,sum; i <= high; ++i){
        sum = 0;
        for(int j = 0; j < n; ++j){
            sum += (ara[j] - i) * (ara[j] - i);
        }
        out = min(sum, out);
    }
    cout << out << endl;
}

signed main(){
	fastio;
	// int t; cin >> t;
	// while(t--)
		solve();
	return 0;
}
