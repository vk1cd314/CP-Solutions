#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
const int N = 1e7 + 10;
int spf[N], sod[N], cnt[N]; 
 
void hmmm() {      
      spf[1] = 1;
      for (int i = 2; i * i < N; ++i) {
            if (!spf[i]) {
                  spf[i] = i;
                  for (int j = i * i; j < N; j += i) {
                        if (!spf[j]) spf[j] = i;
                  }
            }
      }
 
      sod[1] = 1;
      cnt[1] = 1;
      for (int i = 2; i < N; ++i) {
            if (!spf[i]) {
                  spf[i] = i;
                  sod[i] = i + 1;
                  if (sod[i] < N && !cnt[sod[i]]) cnt[sod[i]] = i;
                  continue;
            }
            int j = i;
            sod[i] = 1;
            while (j % spf[i] == 0) {
                  j /= spf[i];
                  sod[i] = spf[i] * sod[i] + 1;
            }
            sod[i] *= sod[j];
            if (sod[i] < N && !cnt[sod[i]]) cnt[sod[i]] = i;
      }
}
 
 
int main() {
      #ifdef Icry
            auto begin = std::chrono::high_resolution_clock::now();
      #endif
      ios_base :: sync_with_stdio(0);
      cin.tie(0); 
 
      hmmm();
 
      int t; cin >> t;
      while (t--) {
            int64_t c; cin >> c;
            cout << (cnt[c] ? cnt[c] : -1) << '\n';
      }
 
      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}