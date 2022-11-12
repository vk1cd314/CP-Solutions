#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
int main() {
      #ifdef Icry
            auto begin = chrono :: high_resolution_clock :: now();
      #endif
      ios_base :: sync_with_stdio(0);
      cin.tie(0);
 
      int t; cin >> t;
      while (t--) {
            int n; cin >> n;
            string s; cin >> s;
            map <char, int> cnt;
            for (char c : s) cnt[c]++;
 
            char ans = '#';
            for (char c = 'a'; c <= 'z'; ++c) {
                  if (!cnt[c]) {
                        ans = c;
                        break;
                  }
            }
 
            if (ans != '#') {
                  cout << ans << '\n';
                  continue;
            }
 
            set <string> s2, s3;
            int i = 0, sz = (int) s.length();
            while (i + 1 < sz) {
                  s2.insert(s.substr(i, 2));
                  ++i;
            }
            debug(s2);
 
            bool ok1 = false;
            string curr, hha;
            for (char c = 'a'; c <= 'z' && !ok1; ++c) {
                  for (char d = 'a'; d <= 'z' && !ok1; ++d) {
                        curr = "";
                        curr += c;
                        curr += d;
                        debug(c, d);
                        debug(curr);
                        if (!s2.count(curr)) {
                              ok1 = true;
                              hha = curr;
                              break;
                        }
                  }
            }
 
            if (ok1) {
                  cout << hha << '\n';
                  continue;
            }
 
            i = 0;
            while (i + 2 < sz) {
                  s3.insert(s.substr(i, 3));
                  i++;
            }
            debug(s3);
 
            for (char c = 'a'; c <= 'z' && !ok1; ++c) {
                  for (char d = 'a'; d <= 'z' && !ok1; ++d) {
                        for (char e = 'a'; e <= 'z' && !ok1; ++e) {
                              curr = "";
                              curr += c;
                              curr += d;
                              curr += e;
                              if (!s3.count(curr)) {
                                    ok1 = true;
                                    hha = curr;
                                    break;
                              }
                        }
                  }     
            }
 
            assert(!hha.empty());
            cout << hha << '\n';
      }
 
      #ifdef Icry
            auto end = chrono :: high_resolution_clock :: now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono :: duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}