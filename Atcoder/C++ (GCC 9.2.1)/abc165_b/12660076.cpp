#include<bits/stdc++.h>
#define int long long int
using namespace std;

signed main(){
    int x; cin >> x;
    int ans = 0;

    int val = 100;

    while (val < x) {
        val += val / 100;
        ans++;
    }
    cout << ans << endl;
    return 0;
}