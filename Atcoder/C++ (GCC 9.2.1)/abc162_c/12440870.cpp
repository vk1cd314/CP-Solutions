#include <bits/stdc++.h>
#define int long long int
#define endl '\n'
using namespace std;

void solve(){
   int n,ans = 0; cin >> n;

   for(int i = 1; i <= n; ++i){
       for(int j = 1; j <= n; ++j){
           for(int k = 1 ; k <= n; ++k){
               ans += __gcd(__gcd(i,j),k);
           }
       }
   }
   cout << ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}