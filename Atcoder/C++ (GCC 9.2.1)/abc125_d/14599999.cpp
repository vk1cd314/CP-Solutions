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

void solve(){
    cin >> n;
    vector<int> ara(n);
    int negs = 0;
    int minpos = 1e9 + 69;
    bool zeroes = false;
    for(int& i : ara){
        cin >> i;
        if(i == 0)
            zeroes = true;
        if(i < 0)
            ++negs;
        minpos = min(minpos, abs(i));
    }
    int sum = 0;
    for(int i : ara)
        sum += abs(i);
    if(zeroes)
        cout << sum << endl;
    else if(negs&1^1)
        cout << sum << endl;
    else
        cout << sum - 2*minpos << endl; 
}

int32_t main(){
	ios_base::sync_with_stdio(false),cin.tie(nullptr);
	// int t; cin >> t;
	// while(t--)
		solve();
	return 0;
}
