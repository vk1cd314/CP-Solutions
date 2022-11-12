#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
const int64_t mx = 1e10, N = 10000;
int dp[N];
 
int main() {
      #ifdef Icry
            auto begin = chrono :: high_resolution_clock :: now();
      #endif
      ios_base :: sync_with_stdio(0);
      cin.tie(0);
 
      int64_t st = 11;
      set <int64_t> hmm;
      while (st < mx) hmm.insert(st), st = st * 10LL + 1LL;
 
      memset(dp, 0, sizeof dp);
      for (auto dd : hmm) if (dd < N) dp[dd] = 1;
 
      for (int i = 0; i < N; ++i) {
            for (auto dd : hmm) {
                  if (i - dd >= 0) dp[i] |= dp[i - dd];
            }
            // if (!dp[i]) {
            //       // debug(i);
            // }
      }
 
      // for ()
 
      int t; cin >> t;
      while (t--) {
            int64_t x; cin >> x;
            if (x >= N) cout << "YES\n";
            else {
                  if (dp[x]) cout << "YES\n";
                  else cout << "NO\n";
            }
      }
 
      #ifdef Icry
            auto end = chrono :: high_resolution_clock :: now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono :: duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}