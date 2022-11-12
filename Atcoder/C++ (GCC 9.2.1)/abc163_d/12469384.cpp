#include <bits/stdc++.h>
#define int long long int
#define MAXN 1000000007
#define endl '\n'
using namespace std;

//int binomialCoeff(int n, int k){
//    int res = 1;
//    if ( k > n - k )
//        k = n - k;
//    for (int i = 0; i < k; ++i){
//        res *= (n - i);
//        res /= (i + 1);
//    }
//    return res;
//}

void solve(){
    int n, k, sum = 0; cin >> n >> k;

    for(int i = k ; i <= n+1; ++i){
        sum += i*n - i*(i-1)/2 - (i-1)*i/2 + 1;
    }
    cout << sum % MAXN << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}