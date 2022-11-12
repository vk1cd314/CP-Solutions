#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
int main() {
      // ios_base::sync_with_stdio(0);
      // cin.tie(0);
 
      int n, q; cin >> n >> q;
      string s; cin >> s;
      int curr = 0;
      set <int> ids;
      for (int i = 0; i + 2 < n; ++i) {
            if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c') {
                  ids.insert(i);
                  ids.insert(i + 1);
                  ids.insert(i + 2);
                  curr++;
            }
      }
 
      debug(curr);
      while (q--) {
            int i;
            char c;
            cin >> i >> c;
            --i;
            if (c == 'a') {
                  auto it = ids.find(i);
                  if (it != ids.end()) {
                        if (i + 2 < n && s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c') {
                              ids.erase(i), ids.erase(i + 1), ids.erase(i + 2);
                              --curr;
                        } 
                        if (i > 0 && i + 1 < n && s[i - 1] == 'a' && s[i] == 'b' && s[i + 1] == 'c') {
                              ids.erase(i - 1), ids.erase(i), ids.erase(i + 1);
                              --curr;
                        }
                        if (i > 1 && s[i - 2] == 'a' && s[i - 1] == 'b' && s[i] == 'c') {
                              ids.erase(i - 2), ids.erase(i - 1), ids.erase(i);
                              --curr;
                        }
                  }
                  s[i] = c;
                  if (i + 2 < n && s[i + 1] == 'b' && s[i + 2] == 'c') {
                        ids.insert(i), ids.insert(i + 1), ids.insert(i + 2);
                        ++curr;
                  }
            } else if (c == 'b') {
                  auto it = ids.find(i);
                  if (it != ids.end()) {
                        if (i + 2 < n && s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c') {
                              ids.erase(i), ids.erase(i + 1), ids.erase(i + 2);
                              --curr;
                        } 
                        if (i > 0 && i + 1 < n && s[i - 1] == 'a' && s[i] == 'b' && s[i + 1] == 'c') {
                              ids.erase(i - 1), ids.erase(i), ids.erase(i + 1);
                              --curr;
                        }
                        if (i > 1 && s[i - 2] == 'a' && s[i - 1] == 'b' && s[i] == 'c') {
                              ids.erase(i - 2), ids.erase(i - 1), ids.erase(i);
                              --curr;
                        }
                  }
                  s[i] = c;
                  if (i > 0 && i + 1 < n && s[i - 1] == 'a' && s[i] == 'b' && s[i + 1] == 'c') {
                        ids.insert(i - 1), ids.insert(i), ids.insert(i + 1);
                        ++curr;
                  }
            } else {
                  auto it = ids.find(i);
                  if (it != ids.end()) {
                        if (i + 2 < n && s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c') {
                              ids.erase(i), ids.erase(i + 1), ids.erase(i + 2);
                              --curr;
                        } 
                        if (i > 0 && i + 1 < n && s[i - 1] == 'a' && s[i] == 'b' && s[i + 1] == 'c') {
                              ids.erase(i - 1), ids.erase(i), ids.erase(i + 1);
                              --curr;
                        }
                        if (i > 1 && s[i - 2] == 'a' && s[i - 1] == 'b' && s[i] == 'c') {
                              ids.erase(i - 2), ids.erase(i - 1), ids.erase(i);
                              --curr;
                        }
                  }
                  s[i] = c;
                  if (i > 1 && s[i - 2] == 'a' && s[i - 1] == 'b' && s[i] == 'c') {
                        ids.insert(i - 2), ids.insert(i - 1), ids.insert(i);
                        ++curr;
                  }
            }
            s[i] = c;
            // debug(s);
            cout << curr << '\n';
      }
}