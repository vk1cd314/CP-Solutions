#include <bits/stdc++.h>
#define int long long int
#define endl '\n'
using namespace std;

void solve(){
   string s; cin >> s;
   bool ans = false;
   if(s[0]=='7'||s[1]=='7'||s[2]=='7') ans = true;
   cout << (ans?"Yes":"No");
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}