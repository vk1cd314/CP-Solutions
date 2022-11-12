#include <bits/stdc++.h>
#define int long long int
#define endl '\n'
using namespace std;

void solve(){
    int x,y,z; cin >> x >> y >> z;
    swap(x,y);
    swap(x,z);
    cout << x << " " << y << " " << z << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}