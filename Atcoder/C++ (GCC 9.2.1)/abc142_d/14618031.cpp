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

int a, b;

bool isprime(int n){
    if(n == 1)
        return true;
    for(int i = 2; i*i <= n; ++i)
        if(n%i == 0)
            return false;
    return true;
}

void solve(){
    cin >> a >> b;
    vector<int> cdiv;
    for(int i = 1; i*i <= a; ++i){
        if(a%i == 0){
            if(b%i == 0 and isprime(i))
                cdiv.emplace_back(i);
            if(b%(a/i) == 0 and a != i*i and isprime(a/i))
                cdiv.emplace_back(a/i);
        }
    }
    cout << (cdiv.empty() ? 0 : cdiv.size()) << endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false),cin.tie(nullptr);
	// int t; cin >> t;
	// while(t--)
		solve();
	return 0;
}
