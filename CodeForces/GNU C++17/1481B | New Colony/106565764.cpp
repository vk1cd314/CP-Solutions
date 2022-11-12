#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef SENDHELP
#include "debug.h"
#else
#define debug(args...)
#endif
 
int main() {
#ifdef SENDHELP
      auto begin = std::chrono::high_resolution_clock::now();
#endif
      ios_base ::sync_with_stdio(0);
      cin.tie(0);
 
      int t;
      cin >> t;
      while (t--) {
            int64_t n, k;
            cin >> n >> k;
            vector <int64_t> a(n);
            for (auto &x : a) cin >> x;
 
            int ans;
            if (k > 10000) k = 10000;
            while (k--) {
                  ans = 0;
                  for (int j = 0; j + 1 < n; j++) {
                        if (a[j] >= a[j + 1]) ans++;
                        else break;
                  }
                  if (ans < n - 1) a[ans]++;
            }
            if (ans < n - 1) cout << ans + 1 << endl;
            else cout << -1 << endl;
      }
 
#ifdef SENDHELP
      auto end = std::chrono::high_resolution_clock::now();
      cerr << setprecision(4) << fixed;
      cerr << "[Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds]\n";
#endif
}