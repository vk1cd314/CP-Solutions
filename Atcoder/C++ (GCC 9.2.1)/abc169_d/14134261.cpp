#include "bits/stdc++.h"
#define int long long
#define all(c) (c).begin(), (c).end()
#define cpresent(c,x) ((c).find(x) != (c).end()) // present in container?
#define vpresent(c,x) (find(all(c),x) != (c).end()) // present in vector?
#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr), cout.tie(nullptr)
#define endl '\n'
using namespace std;

int n;

bool isprime(int n){
    if(n == 1)
        return false;
    for(int i = 2; i*i <= n; ++i){
        if(n%i == 0)
            return false;
    }
    return true;
}

int cnt(vector<int>& fac, int n){
    int ret = 0;
    for(int i = 0 ; i < fac.size(); ++i){
        int temp = fac[i];
        int ans = 0;
        while(n%temp == 0){
            n /= temp;
            ans++;
        }
        // cout << "a " << ans << endl;
        ans = (sqrt(1 + 8*ans) - 1)/2;
        // cout << "a1 " << ans << endl;
        ret += ans;
    }
    return ret;
}

void solve(){   
    cin >> n;
    if(n == 1){
        cout << 0 << endl;
        return;
    }
    vector<int> fac;
    for(int i = 1; i*i <= n; ++i){
        if(n%i == 0){
            if(i*i == n){
                if(isprime(i))
                    fac.emplace_back(i);
            }else{
                if(isprime(i))
                    fac.emplace_back(i);
                if(isprime(n/i))
                    fac.emplace_back(n/i);
            }
        }
    }
    // cout << "v\n";
    // for(int i = 0; i < fac.size(); ++i)
    //     cout << fac[i] << " ";
    // cout << endl;
    cout << cnt(fac, n) << endl;
}
signed main(){
	fastio;
	// int t; cin >> t;
	// while(t--)
		solve();
	return 0;
}
