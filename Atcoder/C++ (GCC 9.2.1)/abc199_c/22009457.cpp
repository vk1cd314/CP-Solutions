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

      int n; cin >> n;
      string s; cin >> s;

      int q; cin >> q;
      vector <pair <int, int>> need;
      int cnt = 0;
      while (q--) {
            int t, a, b; cin >> t >> a >> b;
            --a, --b;
            if (t == 1) {
                  if (cnt % 2 == 0) {
                        swap(s[a], s[b]);
                  } else {
                        if (a < n) a += n;
                        else a -= n;
                        if (b < n) b += n;
                        else b -= n;
                        swap(s[a], s[b]);
                  }
            }
            else ++cnt;
      }

      if (cnt & 1) {
            for (int i = n; i < 2 * n; ++i) cout << s[i];
            for (int i = 0; i < n; ++i) cout << s[i];
      } else {
            cout << s << '\n';
      }

      #ifdef Icry
            auto end = chrono :: high_resolution_clock :: now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono :: duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}