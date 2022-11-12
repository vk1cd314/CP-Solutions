#include <bits/stdc++.h>
#define int long long int
#define endl '\n'
using namespace std;

int a[110];

void solve(){
    int n , m, sum = 0 , cnt = 0; cin >> n >> m;

    for(int i = 0 ; i < n; ++i){
        cin >> a[i];
        sum += a[i];
    }

    for(int i = 0 ; i < n; ++i){
        if(a[i]*4*m >= sum) cnt++;
    }

    if(cnt >= m){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}