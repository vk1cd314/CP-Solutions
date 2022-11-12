#include <bits/stdc++.h>
#define int long long int
#define MAXN 1000000007
#define endl '\n'
using namespace std;

void solve(){
    int n; cin >> n;
    set<string> s;

    for(int i = 0; i < n ; ++i){
        string str;
        cin >> str;
        s.insert(str);
    }

    cout << s.size();
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();

    return 0;
}