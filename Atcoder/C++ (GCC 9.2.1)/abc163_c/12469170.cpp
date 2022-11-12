#include <bits/stdc++.h>
#define int long long int
#define endl '\n'
using namespace std;

int a[200010], ans[200010];

void solve(){
    int n; cin >> n;
    for(int i = 2; i <= n; ++i) cin >> a[i];
    for(int i = 2; i <= n ; ++i) ans[a[i]]++;
    for(int i = 1 ; i <= n; ++i) cout << ans[i] << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}