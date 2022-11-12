#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
int get(int i, int j, int k) {
      cout << "? " << i << ' ' << j << ' ' << k << endl;
      int ret; cin >> ret;
      return ret;
}
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      int t; cin >> t;
      while (t--) {
            int n; cin >> n;
            vector <int> ext;
            vector <int> ids;
            for (int i = 1; i <= n; ++i) {
                  ids.push_back(i);
                  if (ids.size() == 4) {
                        vector <pair <int, int>> curr;
                        int a = ids[0], b = ids[1], c = ids[2], d = ids[3];
                        curr.push_back(pair <int, int>(get(b, c, d), a));
                        curr.push_back(pair <int, int>(get(a, c, d), b));
                        curr.push_back(pair <int, int>(get(a, b, d), c));
                        curr.push_back(pair <int, int>(get(a, b, c), d));
                        sort(curr.begin(), curr.end());
                        assert(curr[3].first == curr[2].first);
                        ext.push_back(curr.back().second);
                        curr.pop_back();
                        ext.push_back(curr.back().second);
                        curr.pop_back();
                        ids.clear();
                        ids.push_back(curr[0].second);
                        ids.push_back(curr[1].second);
                  }
            }
 
            if (ids.size() != 2) {
                  assert((int) ext.size() >= 1);
                  ids.push_back(ext[0]);
                  vector <pair <int, int>> curr;
                  int a = ids[0], b = ids[1], c = ids[2], d = ids[3];
                  curr.push_back(pair <int, int>(get(b, c, d), a));
                  curr.push_back(pair <int, int>(get(a, c, d), b));
                  curr.push_back(pair <int, int>(get(a, b, d), c));
                  curr.push_back(pair <int, int>(get(a, b, c), d));
                  sort(curr.begin(), curr.end());
                  assert(curr[3].first == curr[2].first);
                  ext.push_back(curr.back().second);
                  curr.pop_back();
                  ext.push_back(curr.back().second);
                  curr.pop_back();
                  ids.clear();
                  ids.push_back(curr[0].second);
                  ids.push_back(curr[1].second);
            }
 
            cout << "! "  << ids[0] << ' ' << ids[1] << endl;
      }
}