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

int n, q;

void solve(){
    cin >> n;
    int sum = 0;
    vector<int> freq(100069, 0); 
    for(int i = 0, inp; i < n; ++i){
        cin >> inp;
        freq[inp]++;
        sum += inp;
    }
    cin >> q;
    while(q--){
        int b, c;
        cin >> b >> c;
        sum -= freq[b]*b;
        sum += freq[b]*c;
        freq[c] += freq[b];
        freq[b] = 0;
        cout << sum << endl;
    }
}

int32_t main(){
	ios_base::sync_with_stdio(false),cin.tie(nullptr);
	// int t; cin >> t;
	// while(t--)
		solve();
	return 0;
}
