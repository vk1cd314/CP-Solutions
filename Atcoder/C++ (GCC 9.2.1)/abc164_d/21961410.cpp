#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif

using namespace std;

int main() {
      #ifdef Icry
            auto begin = chrono :: high_resolution_clock :: now();
      #endif
      ios_base :: sync_with_stdio(0);
      cin.tie(0);

      string s; cin >> s;
      map <int, int> rem;
      
      int64_t ans = 0, tot = 0, pw = 1;
      rem[tot]++;
      reverse(s.begin(), s.end());
      for (char c : s) {
            tot = (tot + (c - '0') * pw) % 2019;
            debug(tot);
            ans += rem[tot];
            rem[tot]++;
            pw = (pw * 10) % 2019;
      }

      cout << ans << '\n';

      #ifdef Icry
            auto end = chrono :: high_resolution_clock :: now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono :: duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}