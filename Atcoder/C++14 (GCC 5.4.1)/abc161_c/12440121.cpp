#include <bits/stdc++.h>
#define int long long int
#define endl '\n'
using namespace std;

void solve(){
   int n, k, ans; cin >> n >> k;

   if(k == 1) cout << 0 << endl;
   else{
        ans = n % k;
        cout << min(ans, k - ans);
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}