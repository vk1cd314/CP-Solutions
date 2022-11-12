#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c, d, e; cin >> a >> b >> c >> d >> e;
    map <int, int> mp;

    mp[a]++;
    mp[b]++;
    mp[c]++;
    mp[d]++;
    mp[e]++;

    if (mp.size() == 2) {
        auto it = mp.begin();
        auto it1 = next(it);
        int mn = min(it->second, it1->second);
        int mx = max(it->second, it1->second);
        if (mn == 2 && mx == 3) {
            cout << "Yes\n";
        } else cout << "No\n";
    } else cout << "No\n";
}