#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    int a[n];
    for (int i = 2; i <= n; ++i) cin >> a[i];
    int c = n, ans = 0;
    while (c != 1) c = a[c], ans++;
    cout << ans << '\n';
}