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
            int n; cin >> n;
            vector <int64_t> a(n); for (auto &x : a) cin >> x;
 
            // auto lel = [&](vector <int64_t> &a) {
            //       int ret = 0;
            //       for (int i = 0; i < n; ++i) {
            //             for (int j = i + 1; j < n; ++j) {
            //                   ret += abs(a[i] - a[j]);
            //             }
            //       }
            //       return ret;
            // };
 
            // sort(a.begin(), a.end());
            // int mn = INT_MAX;
            // vector <int64_t> smol;
            // do {
            //       if (lel(a) < mn) {
            //             mn = lel(a);
            //             smol = a;
            //       }
            // } while (next_permutation(a.begin(), a.end()));
 
            // debug(mn, smol);
            // def sorted
            // // sort(a)
            // int64_t ans = 0;
            // for (int64_t i = n - 1; i >= 0; --i) {
            //       ans += i * a[i] - (n - 1 - i) * a[i];
            // }
            // cout << ans << '\n';
            // I understood it wrong nothing new
            int64_t sum = accumulate(a.begin(), a.end(), 0LL);
            int64_t have = sum / n;
            int64_t ext = sum % n, ext1 = sum % n;
            vector <int64_t> d1(n, have);
            int i = 0;
            while (ext) d1[i]++, ext--, ++i;
            reverse(d1.begin(), d1.end());
            int64_t ans = 0;
            for (int64_t i = n - 1; i >= 0; --i) {
                  ans += i * d1[i] - (1LL * n - 1 - i) * d1[i];
            }
            vector <int64_t> d2(n, have);
            d2[n - 1] += ext1;
            debug(d2);
            int64_t ans2 = 0;
            for (int64_t i = n - 1; i >= 0; --i) {
                  ans2 += i * d2[i] - (1LL * n - 1 - i) * d2[i];
            }
 
            debug(ans, ans2);
            cout << min(ans, ans2) << '\n';
      }
 
      #ifdef Icry
            auto end = chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono::duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}