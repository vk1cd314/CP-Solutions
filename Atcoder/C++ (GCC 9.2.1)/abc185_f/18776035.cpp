#include <bits/stdc++.h>

using namespace std;

#ifdef BOI
#include "debug.h"
#else
#define debug(args...)
#endif

const int N = 3e5 + 2;
long long a[N], T[N], n;
 
void update(int id, long long val) {
      for (;id <= n; id += (id & -id)) T[id] ^= val;
}
 
long long x0r(int id) {
      long long x0r = 0;
      for (;id > 0; id -= (id & -id)) x0r ^= T[id];
      return x0r;
}

int main() {
      ios_base :: sync_with_stdio(0);
      cin.tie(0);

      int q; cin >> n >> q;
      memset(T, 0, sizeof T);
      memset(a, 0, sizeof a);


      for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            update(i, a[i]);
      }

      while (q--) {
            int type; cin >> type;
            if (type == 1) {
                  long long x, y; cin >> x >> y;
                  update(x, y);
                  a[x] = a[x] ^ y;
            } else {
                  int x, y; cin >> x >> y;
                  cout << (x0r(y) ^ x0r(x - 1)) << endl; 
            }
      }
      
}
