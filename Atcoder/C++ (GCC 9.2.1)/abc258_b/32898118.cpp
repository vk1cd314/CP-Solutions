#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif

using namespace std;

int n;
string a[100];
string ans = "";
int dx[] = {1, -1, 0, 0, -1, 1, 1, -1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1}; 

int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);

      cin >> n;
      for (int i = 0; i < n; ++i) cin >> a[i];

      for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                  for (int k = 0; k < 8; ++k) {
                        string curr = "";
                        for (int l = 0; l < n; ++l) {
                              int ii = i + dx[k] * l, jj = j + dy[k] * l;
                              ii = (ii + n) % n, jj = (jj + n) % n;
                              curr.push_back(a[ii][jj]);
                        }
                        // ans = max(ans, curr);
                        if (curr > ans) {
                              ans = curr;
                              debug(i, j, k, curr);
                        }
                  }
            }
      }
      cout << ans << '\n';
}