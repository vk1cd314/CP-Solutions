#include <bits/stdc++.h>
#define int long long int
#define endl '\n'
using namespace std;

void solve(){
   int n,ans = 0; cin >> n;

   for(int i = 1; i <= n ; ++i){
       if(i%3!=0 && i%5!=0) ans += i;
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