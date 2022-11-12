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
      int64_t k; cin >> k;
      vector <pair <int64_t, int64_t>> a(n);
      for (int i = 0; i < n; ++i) {
            cin >> a[i].first >> a[i].second;
      }

      int64_t curr = 0, have = k;
      sort(a.begin(), a.end(), [&](auto a, auto b) {
            if (a.first == b.first) return a.second > b.second;
            return a.first < b.first;
      });

      if (have >= a[0].first) have -= a[0].first, curr = a[0].first, have += a[0].second;
      else {
            cout << k << '\n';
            return 0;
      }

      for (int i = 1; i < n; ++i) {
            if (have >= a[i].first - a[i - 1].first) have -= a[i].first - a[i - 1].first, curr = a[i].first, have += a[i].second; 
            else break;
      }

      cout << curr + have << '\n';

      #ifdef Icry
            auto end = chrono :: high_resolution_clock :: now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono :: duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}