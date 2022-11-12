    #include "bits/stdc++.h"
    #define int long long
    #define all(c) (c).begin(), (c).end()
    #define cpresent(c,x) ((c).find(x) != (c).end()) 
    #define vpresent(c,x) (find(all(c),x) != (c).end())
    #define endl '\n'
    #ifdef LOCAL
    #include "/home/iggaboi/Desktop/CP/debug.h"
    #else
    #define debug(x...)
    #endif
    using namespace std;

    char c;

    void solve(){
        cin >> c;
        if(c > 96)
            cout << 'a' << endl;
        else
            cout << 'A' << endl;
    }

    int32_t main(){
        ios_base::sync_with_stdio(false),cin.tie(nullptr);
        // int t; cin >> t;
        // while(t--)
            solve();
        return 0;
    }
