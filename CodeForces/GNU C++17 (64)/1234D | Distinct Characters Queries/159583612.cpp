#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
const int N = 1e5 + 2;
int T[N][27], n;
 
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
 
      string s; cin >> s;
      n = s.size();
      for (int i = 0; i < n; ++i) update(i + 1, 1, s[i] - 'a');
      int q; cin >> q;
      while (q--) {
            int t; cin >> t;
            if (t == 1) {
                  int pos;
                  char c;
                  cin >> pos >> c;
                  update(pos, -1, s[pos - 1] - 'a');
                  s[pos - 1] = c;
                  update(pos, 1, s[pos - 1] - 'a');
            } else {
                  int l, r; cin >> l >> r;
                  int ans = 0;
                  for (int i = 0; i < 26; ++i) ans += sum(r, i) - sum(l - 1, i) > 0;
                  cout << ans << '\n';
            }
      }
}