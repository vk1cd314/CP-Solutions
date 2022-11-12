#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
const int N = 1e5;
vector <int> primes;
bitset <N> prim;
 
void sieve() {      
      prim[1] = 1;
      for (int i = 2; i * i < N; ++i) {
            if (!prim[i]) {
                  for (int j = i * i; j < N; j += i) {
                        prim[j] = 1;
                  }
            }
      }
 
      for (int i = 2; i < N; ++i) {
            if (!prim[i]) primes.push_back(i);
      }
}
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      sieve();
 
      int t; cin >> t;
      while (t--) {
            int n; cin >> n;
            vector <pair <int, int>> ev, od;
            int ans = 0, s0 = 0;
            for (int i = 0; i < n; ++i) {
                  int x; cin >> x;
                  if (x & 1) od.push_back({x, i}), s0 += x;
                  else ev.push_back({x, i}), ans += x;
            }
            if (((int)od.size()) & 1) {
                  if (prim[ans + s0]) {
                        cout << n << '\n';
                        for (int i = 1; i <= n; ++i) cout << i << ' ';
                        cout << '\n';
                  } else {
                        cout << n - 1 << '\n';
                        for (auto [x, i] : ev) cout << i + 1 << ' ';
                        for (int i = 1; i < (int) od.size(); ++i) {
                              cout << od[i].second + 1 << ' ';
                        }
                        cout << '\n';
                  }
            } else {
                  cout << n << '\n';
                  for (int i = 1; i <= n; ++i) cout << i << ' ';
                  cout << '\n';
            }
      }
}