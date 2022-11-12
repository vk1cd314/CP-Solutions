#include <bits/stdc++.h>
#define int long long int
#define endl '\n'
using namespace std;

void solve(){
   int n, m, sum = 0; cin >> n >> m;

   for(int i = 0 ; i < m ;++i){
       int x; cin >> x;
       sum += x;
   }

   if(sum > n) cout << -1 << endl;
   else cout << n - sum << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}