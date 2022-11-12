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
            int64_t n, k; cin >> n >> k;
            vector <int64_t> x(k); for (auto &s : x) cin >> s;
            sort(x.rbegin(), x.rend());
            int64_t tot = 0;
            for (int i = 0; i < k; ++i) tot += n - x[i];
            priority_queue <int64_t> pq;
            for (int i = 0; i < k; ++i) pq.push(x[i]);
 
            int64_t cat = 0;
            int64_t free = 0;
            while (!pq.empty()) {
                  int64_t xx = pq.top();
                  if (cat >= xx) break;
                  cat += n - xx;
                  free++;
                  pq.pop();
            }
            cout << free << '\n';
      }
}