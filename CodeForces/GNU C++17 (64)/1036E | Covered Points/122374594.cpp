#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
const int NEUTRAL = 1e9 + 69;
const pair <int, int> npp = {NEUTRAL, NEUTRAL};
 
struct point {
      int64_t x, y;
};
 
const point neut = {NEUTRAL, NEUTRAL};
 
bool onSegment(point p, point q, point r) {
      if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
            q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
            return true;
      
      return false;
}
 
struct seg {
      point a, b;
      point intersect(const seg &x) {
            int64_t a1 = b.y - a.y;
            int64_t b1 = a.x - b.x;
            int64_t c1 = a1 * a.x + b1 * a.y;
 
            int64_t a2 = x.b.y - x.a.y;
            int64_t b2 = x.a.x - x.b.x;
            int64_t c2 = a2 * x.a.x + b2 * x.a.y;
 
            int64_t det = a1 * b2 - a2 * b1;
            if (!det) return neut;
 
            if ((b2 * c1 - b1 * c2) % det) return neut;
            if ((a1 * c2 - a2 * c1) % det) return neut;
 
            point ret = {(b2 * c1 - b1 * c2) / det, (a1 * c2 - a2 * c1) / det};
            if (!onSegment(a, ret, b) || !onSegment(x.a, ret, x.b)) return neut;
            return ret;
      };
};
 
int main() {
      #ifdef Icry
            auto begin = chrono::high_resolution_clock::now();
      #endif
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      int n; cin >> n;
      vector <seg> a(n); 
      int64_t ans = 0;
      for (auto &s : a) {
            cin >> s.a.x >> s.a.y >> s.b.x >> s.b.y;
            int64_t dx = abs(s.a.x - s.b.x);
            int64_t dy = abs(s.a.y - s.b.y);
            ans += __gcd(dx, dy) + 1;
      }
 
      map <pair <int, int>, set <int>> cnt;
      for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                  point lel = a[i].intersect(a[j]);
                  cnt[{lel.x, lel.y}].insert(i);
                  cnt[{lel.x, lel.y}].insert(j);
            }
      }
 
      for (auto [pp, ct] : cnt) {
            if (pp != npp) ans -= ct.size() - 1;
      }
 
      cout << ans << '\n';
 
      #ifdef Icry
            auto end = chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono::duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}