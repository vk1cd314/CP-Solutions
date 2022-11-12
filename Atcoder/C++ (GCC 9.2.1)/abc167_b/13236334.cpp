#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int a, b, c, k; cin >> a >> b >> c >> k;

	int ans = 0;
	if (k < a)
		ans = k;
	else if (k >= a && k <= a + b)
		ans += a;
	else
		ans = a - (k - a - b);

	cout << ans << endl;

	return 0;
}