#include "bits/stdc++.h"
#define int long long
#define all(c) (c).begin(), (c).end()
#define cpresent(c,x) ((c).find(x) != (c).end()) // present in container?
#define vpresent(c,x) (find(all(c),x) != (c).end()) // present in vector?
#define endl '\n'
using namespace std;

int luca(int n){
    vector<int> lucas(n + 1);
    lucas[0] = 2;
    lucas[1] = 1;
    for(int i = 2; i <= n ; ++i){
        lucas[i] = lucas[i - 1] + lucas[i - 2]; 
    }
    return lucas[n];
}

int n; 

void solve(){
    cin >> n;
    cout << luca(n) << endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	// int t; cin >> t;
	// while(t--)
		solve();
	return 0;
}
