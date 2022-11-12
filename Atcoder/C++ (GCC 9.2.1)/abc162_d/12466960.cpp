#include <bits/stdc++.h>
#define int long long int
#define endl '\n'
using namespace std;

int binomialCoeff(int n, int k){
    if(n < k) return 0;
    int res = 1;
    if ( k > n - k )
        k = n - k;
    for (int i = 0; i < k; ++i){
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}
void solve(){
   int n;
   string s;
   cin >> n >> s;
   int nred = 0, nblue = 0, ngreen = 0;

   for(int i = 0; i < n; ++i){
       if(s[i] == 'R') ++nred;
       if(s[i] == 'G') ++ngreen;
       if(s[i] == 'B') ++nblue;
   }
//   cout << nred << " " << ngreen << " " << nblue << endl;
//   cout << binomialCoeff(nred,3) << " " << binomialCoeff(ngreen,3) << " " << binomialCoeff(nblue,3) << endl;
   int res = binomialCoeff(n,3) - binomialCoeff(nred,3) - binomialCoeff(ngreen,3) - binomialCoeff(nblue, 3) ;
//   cout << res<< endl;
   res -= binomialCoeff(nred,2)*(ngreen + nblue) + binomialCoeff(ngreen,2)*(nred + nblue) + binomialCoeff(nblue,2)*(ngreen + nred);
//   cout << res << endl;

   for(int i = 0; i < n; ++i){
       for(int j = 0; i + 2*j < n; ++j){
           if(s[i] == s[i + j] || s[i + j] == s[i + 2*j] || s[i] == s[i + 2*j]) continue;
           else --res;
       }
   }
   cout << res;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}