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

int binpow(int a, int n){
    if(n == 0)
        return 1;
    return (n&1 ? binpow(a, n/2)*binpow(a, n/2)*a : binpow(a, n/2)*binpow(a, n/2));
}

void solve(){
    cin >> n;
    string s = "";
    while(n){
        n--;
        int rem = n%26;
        n /= 26;
        char c = 'a' + rem;
        s += c;
    }
    reverse(s.begin(), s.end());
    cout << s << endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false),cin.tie(nullptr);
	// int t; cin >> t;
	// while(t--)
		solve();
	return 0;
}
