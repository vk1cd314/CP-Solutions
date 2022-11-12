#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
const int N = 1e3 + 10;
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
      outer: while (t--) {
            int n; cin >> n;
            string s; cin >> s;
            set <int> nop;
            nop.insert(1);
            nop.insert(4);
            nop.insert(6);
            nop.insert(8);
            nop.insert(9);
            for (int x : nop) {
                  if (count(s.begin(), s.end(), char('0' + x)) != 0) {
                        cout << "1\n" << x << '\n';
                        goto outer;
                  }
            }
            int ans = 1e9, sz = 1e9;
            for (int i = 0; i < n; ++i) {
                  for (int j = i + 1; j < n; ++j) {
                        string ss;
                        ss.push_back(s[i]);
                        ss.push_back(s[j]);
                        int kek = stoi(ss);
                        if (prim[kek]) {
                              if (2 < sz) ans = kek, sz = 2;
                        }
                        for (int k = j + 1; k < n; ++k) {
                              ss.push_back(s[k]);
                              int kekw = stoi(ss);
                              if (prim[kekw]) {
                                    if (3 < sz) ans = kek, sz = 3;
                              }
                              ss.pop_back();
                        }
                  }
            }
            // assert(false);
            cout << sz << '\n' << ans << '\n';
            // keking fat Ws
      }
}