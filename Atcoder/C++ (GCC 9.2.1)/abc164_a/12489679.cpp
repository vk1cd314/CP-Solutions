#include <bits/stdc++.h>
#define int long long int
#define MAXN 1000000007
#define endl '\n'
using namespace std;

void solve(){
    int s, w; cin >> s >> w;

    cout << ((w>=s)?"unsafe":"safe");
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}