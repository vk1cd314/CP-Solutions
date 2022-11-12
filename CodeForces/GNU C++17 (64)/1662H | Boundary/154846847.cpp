#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      int t; cin >> t;
      while (t--) {
            int64_t w, l; cin >> w >> l;
            vector <int64_t> tofac;
            tofac.push_back(__gcd(w, l - 2));
            tofac.push_back(__gcd(w - 2, l));
            tofac.push_back(__gcd(w - 1, l - 1));
            tofac.push_back(__gcd(l, __gcd(w - 1, l - 2)));
            tofac.push_back(__gcd(w, __gcd(w - 2, l - 1)));
 
            set <int64_t> ss;
            for (auto pp : tofac) {
                  for (int64_t i = 1; i * i <= pp; ++i) {
                        if (pp % i == 0) {
                              ss.insert(i);
                              if (pp / i != i) ss.insert(pp / i);
                        } 
                  }
            }
            assert((int) ss.size() <= 200000);
            cout << ss.size() << ' ';
            for (auto x : ss) cout << x << ' ';
            cout << '\n';
      }
}