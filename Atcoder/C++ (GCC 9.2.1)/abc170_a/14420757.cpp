#include "bits/stdc++.h"
#define int long long
#define all(c) (c).begin(), (c).end()
#define cpresent(c,x) ((c).find(x) != (c).end()) 
#define vpresent(c,x) (find(all(c),x) != (c).end())
#define endl '\n'
using namespace std;

int a,b,c,d,e;

void solve(){
	cin >> a >> b >> c >> d >> e;
    if(a == 0)
        cout << 1 << endl;
    if(b == 0)
        cout << 2 << endl;
    if(c == 0)
        cout << 3 << endl;
    if(d == 0)
        cout << 4 << endl;
    if(e == 0)
        cout << 5 << endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false),cin.tie(nullptr);
	// int t; cin >> t;
	// while(t--)
		solve();
	return 0;
}
