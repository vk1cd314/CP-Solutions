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
            int n; cin >> n;
            string s; cin >> s;
            auto is_vowel = [&](char c) {
                  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
            };
            vector <int> p(n);
            for (int i = 0; i < n; ++i) {
                  if (i != 0 && is_vowel(s[i])) {
                        p[i - 1]++;
                  }
            }
            for (int i = n - 2; i >= 0; --i) p[i] += p[i + 1]; 
            // debug(p);
            vector <pair <int, int>> pfs;
            int id = -1;
            for (int i = 0; i < n; ++i) {
                  long long s = p[i];
                  if (!s) {
                        id = i;
                        break;
                  }
                  // debug(s);
                  if (pfs.empty()) pfs.push_back({s, i});
                  else if (pfs.back().first == s) pfs.back().second = i;
                  else pfs.push_back({s, i});
            }
            // debug(pfs);
            int sz = pfs.size();
            vector <pair <int, int>> vv;
            int lst = 0;
            map <pair <int, int>, bool> rev;
            for (int i = 0; i < sz; ++i) {
                  vv.push_back({lst, pfs[i].second});
                  rev[{lst, pfs[i].second}] = (pfs[i].first & 1);
                  lst = pfs[i].second + 1;
            }
            debug(vv);
            for (int i = sz - 1; i >= 0; i -= 2) {
                  int l = vv[i].first, r = vv[i].second;
                  if (rev[vv[i]]) {
                        for (int j = r; j >= l; --j) cout << s[j]; 
                  } else {
                        for (int j = l; j <= r; ++j) cout << s[j];
                  }
            }
            for (int i = sz % 2; i < sz; i += 2) {
                  int l = vv[i].first, r = vv[i].second;
                  if (rev[vv[i]]) {
                        for (int j = r; j >= l; --j) cout << s[j]; 
                  } else {
                        for (int j = l; j <= r; ++j) cout << s[j];
                  }
            }

            if (id != -1) {
                  for (int i = id; i < n; ++i) cout << s[i]; 
            }
            cout << '\n';
      }
}