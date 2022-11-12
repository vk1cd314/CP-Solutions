#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define cpresent(c,x) ((c).find(x) != (c).end()) 
#define vpresent(c,x) (find(all(c),x) != (c).end())
#define endl '\n'
#ifdef LOCAL
#include "/home/iggaboi/Desktop/CP/debug.h"
#else
#define debug(Args...)
#endif
using ll = long long;
using namespace __gnu_pbds;
using namespace std;
template<class T>
using indexed_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;

char grid[69][69];

void shit() {
	int h, w; cin >> h >> w;
    // char grid[h][w];
    for(int i = 1; i <= h; ++i) for(int j = 1; j <= w; ++j) cin >> grid[i][j];
    int cnt = 0;
    for(int i = 1; i <= h; ++i) {
        for(int j = 1; j <= w; ++j) {
            if (grid[i][j] == '#' && grid[i][j - 1] != '#' && grid[i - 1][j] != '#' && grid[i][j + 1] != '#' && grid[i + 1][j] != '#') ++cnt;
        }
    }
    cout << (!cnt ? "Yes\n" : "No\n");
}

int32_t main() {
	ios_base::sync_with_stdio(false),cin.tie(nullptr);
	// int t; cin >> t;
	// while(t--)
		shit();
	return 0;
}
