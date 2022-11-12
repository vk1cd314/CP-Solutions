#include "bits/stdc++.h"
#define int long long
#define all(c) (c).begin(), (c).end()
#define cpresent(c,x) ((c).find(x) != (c).end()) 
#define vpresent(c,x) (find(all(c),x) != (c).end())
#define endl '\n'
using namespace std;

int x, y, a, b;

void solve(){
	cin >> x >> y;
    if(y&1^1 and 2*x <= y and y <= 4*x){
        cout << "Yes\n";
        return;
    }
    cout << "No\n";
}

int32_t main(){
	ios_base::sync_with_stdio(false),cin.tie(nullptr);
	// int t; cin >> t;
	// while(t--)
		solve();
	return 0;
}
