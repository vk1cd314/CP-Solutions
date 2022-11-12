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
            int n, k; cin >> n >> k;
            map <long long, int> have;
            map <long long, int> id, idL;
            vector <long long> u(n); for (auto &x : u) cin >> x, have[x]++;
            for (int i = 0; i < n; ++i) {
                  if (!id[u[i]]) id[u[i]] = i + 1;
            }
            for (int i = n - 1; i >= 0; --i) {
                  if (!idL[u[i]]) idL[u[i]] = i + 1;
            }
            while (k--) {
                  long long a, b; cin >> a >> b;
                  if (!have[a] || !have[b]) cout << "No\n";
                  else {
                        // cout << (id[a] <= id[b] ? "Yes\n" : "No\n");
                        if (id[a] <= idL[b]) cout << "Yes\n";
                        else cout << "No\n";
                  }
            }
      }
}