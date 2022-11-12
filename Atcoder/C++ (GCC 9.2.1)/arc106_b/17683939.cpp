#include <bits/stdc++.h>

using namespace std;

#ifdef BOI
#include "debug.h"
#else
#define debug(args...)
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
using pii = pair <int, int>;
using pli = pair <ll, int>;
using pll = pair <ll, ll>;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

const ll INF = (ll)2e9 + 69;
const int N = 2e5 + 10;

vector <int> gr[N];
vector <int> vec;
bool vis[N];

void dfs(int u) {
    vec.pb(u);
    vis[u] = true;
    for (int v : gr[u]) {
        if (!vis[v]) dfs(v);
    }
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector <ll> a(n), b(n);
    for (ll& x : a) cin >> x;
    for (ll& x : b) cin >> x;

    while (m--) {
        int u, v; cin >> u >> v;
        --u, --v;
        gr[u].pb(v);
        gr[v].pb(u);
    }

    if (a == b) {
        cout << "Yes";
        return 0;
    }

    ll sum1 = accumulate(all(a), 0);
    ll sum2 = accumulate(all(b), 0);
    if (sum1 != sum2) {
        cout << "No";
        return 0;
    }

    vector <int> bad;
    bool ok = true;
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            vec.clear();
            dfs(i);
            sum1 = 0, sum2 = 0;
            for (int x : vec) sum1 += a[x], sum2 += b[x];
            if (sum1 != sum2) ok = false;
        }
    }

    if (ok) cout << "Yes\n";
    else cout << "No\n";
}
