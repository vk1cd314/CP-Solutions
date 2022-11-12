#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
#define ll long long
 
using namespace std;
 
const int N = 1e5 + 2;
int r[N], c[N], T[N][2], n;
 
void update(int id, int val, int i) {
      for (;id <= n; id += (id & -id)) T[id][i] += val;
}
 
int sum(int id, int i) {
      int sum = 0;
      for (;id > 0; id -= (id & -id)) sum += T[id][i];
      return sum;
}
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      int q;
      cin >> n >> q;
      
      while (q--) {
            int t; cin >> t;
            if (t == 1) {
                  int x, y; cin >> x >> y;
                  if (++r[x] == 1) update(x, 1, 0);
                  if (++c[y] == 1) update(y, 1, 1);
            } else if (t == 2) {
                  int x, y; cin >> x >> y;
                  if (--r[x] == 0) update(x, -1, 0);
                  if (--c[y] == 0) update(y, -1, 1);
            } else {
                  int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
                  if (sum(x2, 0) - sum(x1 - 1, 0) == x2 - x1 + 1 || sum(y2, 1) - sum(y1 - 1, 1) == y2 - y1 + 1) cout << "Yes\n";
                  else cout << "No\n";
            }
      }
}