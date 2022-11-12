#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
int main() {
      #ifdef Icry
            auto begin = chrono::high_resolution_clock::now();
      #endif
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      int t; cin >> t;
      while (t--) {
            int n, k; cin >> n >> k;
            vector <pair <int, int>> chords;
            int done[2 * n + 1];
            memset(done, 0, sizeof done);
            for (int i = 0; i < k; ++i) {
                  int x, y; cin >> x >> y;
                  if (x > y) swap(x, y);
                  chords.push_back({x, y});
                  done[x]++, done[y]++;
            }
 
            int ans = ((n - k) * (n - k - 1)) / 2;
            for (int i = 0; i < k; ++i) {
                  int ct = 0;
                  for (int j = chords[i].first + 1; j < chords[i].second; ++j) {
                        ct += !done[j];
                  }
                  ans += min(ct, 2 * (n - k) - ct);
                  for (int j = i + 1; j < k; ++j) {
                        bool b1 = chords[i].first < chords[j].first && chords[j].first < chords[i].second;
                        bool b2 = chords[i].first < chords[j].second && chords[j].second < chords[i].second;
                        ans += b1 ^ b2;
                  }
            }
            
            cout << ans << '\n';
      }
 
      #ifdef Icry
            auto end = chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono::duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}