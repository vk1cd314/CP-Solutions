#include <bits/stdc++.h>
using namespace std;

#ifdef BOI
#include "debug.h"
#else
#define debug(args...)
#endif

#define all(x) begin(x), end(x)
#define sz(x) (int) x.size()
#define eps 1e-7
#define inf 0x3f3f3f3f
#define endl '\n'

int main() {
    cin.tie(0)->sync_with_stdio(0), cin.exceptions(cin.failbit);
    int n; cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
    }

    vector<vector<int>> dp(n, vector<int>(3, -inf));
    dp[0][0] = a[0];
    dp[0][1] = b[0];
    dp[0][2] = c[0];
    
    for (int i = 1; i < n; ++i) {
        dp[i][0] = max(dp[i - 1][1] + a[i], dp[i - 1][2] + a[i]);
        dp[i][1] = max(dp[i - 1][0] + b[i], dp[i - 1][2] + b[i]);
        dp[i][2] = max(dp[i - 1][0] + c[i], dp[i - 1][1] + c[i]);
    }

    cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
}
// dp[i][j] -> max happiness until ith if he does jth job 1 <= i <= n && 1 <= j <= 3

