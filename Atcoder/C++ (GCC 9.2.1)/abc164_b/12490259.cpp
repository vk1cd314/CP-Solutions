#include <bits/stdc++.h>
#define int long long int
#define MAXN 1000000007
#define endl '\n'
using namespace std;

void solve(){
    int a, b, c, d; cin >> a >> b >> c >> d;
    int cnt1 = 0, cnt2 = 0;
    while(a > 0){
        a -= d;
        cnt1++;
    }
    while(c > 0){
        c -= b;
        cnt2++;
    }
    cout << ((cnt1>=cnt2)?"Yes":"No");
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}