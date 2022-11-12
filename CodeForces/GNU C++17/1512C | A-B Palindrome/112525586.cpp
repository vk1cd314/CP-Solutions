#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
int main() {
      #ifdef Icry
            auto begin = std::chrono::high_resolution_clock::now();
      #endif
      ios_base :: sync_with_stdio(0);
      cin.tie(0);
 
      int t; cin >> t;
      while (t--) {
            int a, b; cin >> a >> b;
            string s; cin >> s;
 
            // if ((int) s.size() == 1) {
            //       if (s[0] == '?') a ? s[0] = '0' : s[0] = '1';
            //       cout << s << '\n';
            //       continue;
            // }
 
            int cnt0 = a, cnt1 = b;
            for (char c : s) {
                  if (c == '0') --cnt0;
                  if (c == '1') --cnt1;
            }
 
            int n = a + b;
            bool ok = true;
            for (int i = 0; i < n / 2 + (n % 2); ++i) {
                  if (s[i] == s[n - 1 - i]) continue;
                  if (s[i] == '1') {
                        if (s[n - 1 - i] == '0') {
                              ok = false;
                              break;
                        }
                        if (s[n - 1 - i] == '?') s[n - 1 - i] = '1', --cnt1;
                  }
                  if (s[i] == '0') {
                        if (s[n - 1 - i] == '1') {
                              ok = false;
                              break;
                        }
                        if (s[n - 1 - i] == '?') s[n - 1 - i] = '0', --cnt0;
                  }
                  if (s[i] == '?') {
                        if (s[n - 1 - i] == '1') s[i] = '1', --cnt1;
                        if (s[n - 1 - i] == '0') s[i] = '0', --cnt0;
                  }
            }     
 
            // debug(cnt1, cnt0, s);
            if (!ok) {
                  cout << "-1\n";
                  continue;
            }
 
            if (cnt1 < 0 or cnt0 < 0) {
                  cout << "-1\n";
                  continue;
            }
 
            // debug(cnt1, cnt0);
            int cc = 0;
            for (int i = 0; i < n; ++i) cc += s[i] == '?';
 
            // debug(cc);
            if (cc % 2 == 0) {
                  if (cnt1 % 2 or cnt0 % 2) {
                        cout << "-1\n";
                  } else {
                        for (int i = 0; i < n / 2 + (n % 2); ++i) {
                              if (s[i] == '?') {
                                    if (cnt0) s[i] = '0', s[n - 1 - i] = '0', cnt0 -= 2;
                                    else if (cnt1) s[i] = '1', s[n - 1 - i] = '1', cnt1 -= 2;
                              } 
                        }
                        cout << s << '\n';
                  }
            } else {
                  for (int i = 0; i < n / 2 + (n % 2); ++i) {
                        if (s[i] == '?') {
                              if (i == n - 1 - i) {
                                    // debug(3);
                                    if (cnt0) s[i] = '0', --cnt0;
                                    else if (cnt1) s[i] = '1', --cnt1;
                                    continue;
                              }
                              if (cnt0 > 1) s[i] = '0', s[n - 1 - i] = '0', cnt0 -= 2;
                              else if (cnt1 > 1) s[i] = '1', s[n - 1 - i] = '1', cnt1 -= 2;
                        }
                  }
                  cout << s << '\n';
            }
      }
 
      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}