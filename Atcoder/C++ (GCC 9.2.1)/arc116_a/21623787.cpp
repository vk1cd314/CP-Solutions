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
            int64_t n; cin >> n;
            int p2 = 0;
            while (n % 2 == 0) n /= 2LL, p2++;

            if (p2 == 0) cout << "Odd\n";
            else if (p2 == 1) cout << "Same\n";
            else cout << "Even\n";

            // vector <int64_t> divs;
            // for (int i = 1; i * i <= n; ++i) {
            //       if (n % i == 0) {
            //             if (i != n / i) divs.push_back(n / i);
            //             divs.push_back(i);
            //       }
            // }
            // sort(divs.begin(), divs.end());
            // int ev = 0, od = 0;
            // debug(divs);
            // for (auto x : divs) x & 1 ? ++od : ++ev;
            // debug(ev, od);
      }

      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}