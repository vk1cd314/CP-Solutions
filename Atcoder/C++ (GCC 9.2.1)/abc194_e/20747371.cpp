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

      int n, m; cin >> n >> m;
      vector <int> a(n); for (int &x : a) cin >> x;
      set <int> s;
      map <int, int> cnt;
      for (int i = 0; i <= n; ++i) s.insert(i);
      for (int i = 0; i < m; ++i) {
            if (s.find(a[i]) != s.end()) s.erase(a[i]);
            cnt[a[i]]++;
      }

      int mi = *s.begin();

      debug(mi);
      for (int i = 1; i < n - m + 1; ++i) {
            cnt[a[i - 1]]--;
            cnt[a[i + m - 1]]++;
            if (cnt[a[i - 1]] == 0) s.insert(a[i - 1]);
            if (s.find(a[i + m - 1]) != s.end()) s.erase(a[i + m - 1]);
            mi = min(mi, *s.begin());
      }

      cout << mi << '\n';

      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}