#include <bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr), cout.tie(nullptr)
#define endl '\n'
using namespace std;

int n, k;

void solve(){   
    cin >> n >> k;
    vector<int> heights(n);
    vector<int> dp(n, INT_MAX); 
    for(int& it : heights)
        cin >> it;
    dp[0] = 0;
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < i + k + 1 && j < n; ++j){
            dp[j] = min(dp[j], dp[i] + abs(heights[i] - heights[j]));
        }
    }
    cout << dp[n - 1] << endl;
}
 
signed main() {
	fastio;
	// int t; cin >> t;
 
	// while(t--)
		solve();
 
	return 0;
}
