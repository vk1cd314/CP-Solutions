#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
string s, t;
 
// bool rec(int i, int j) {
//       if (i == (int) t.size() - 1) return true;
 
//       // debug(i, j);
//       // debug(t[i], s[j]);
//       bool ret = false;
//       if (j - 1 >= 0 && i + 1 < (int) t.size() && t[i + 1] == s[j - 1]) {
//             ret |= rec(i + 1, j - 1);
//       }
//       if (j + 1 < (int) s.size() && i + 1 < (int) t.size() && t[i + 1] == s[j + 1]) {
//             ret |= rec(i + 1, j + 1);
//       }
//       // debug(i, j, ret);
 
//       return ret;
// }
 
int main() {
      #ifdef Icry
            auto begin = chrono::high_resolution_clock::now();
      #endif
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      int T; cin >> T;
      while (T--) {
            // string s, t;
            cin >> s >> t;
            // char st = t[0];
            bool works = false;
            // fucking read question wrong
            for (int i = 0; i < (int) s.size() && !works; ++i) {
                  for (int x = i; x < (int) s.size() && !works; ++x) {
                        string curr = s.substr(i, x - i + 1);
                        if (curr[0] != t[0]) continue;
                        // debug(i, x, curr);
                        if (curr == t) {
                              works = true;
                              break;
                        }
                        for (int y = x - 1; y >= 0 && !works; --y) {
                              curr += s[y];
                              // debug(curr);
                              if (curr == t) {
                                    works = true;
                                    break;
                              }
                        }
                  }
            }
            cout << (works ? "YES\n" : "NO\n");
      }
 
      #ifdef Icry
            auto end = chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono::duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}