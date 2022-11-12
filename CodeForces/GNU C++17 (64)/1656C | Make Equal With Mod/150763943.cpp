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
            int n; cin >> n;
            vector <int64_t> a(n); for (auto &x : a) cin >> x;
            sort(a.begin(), a.end());
            if (a.back() == a[0]) {
                  cout << "YES\n";
                  continue;
            }
            bool ok1 = true, ok2 = true;
            for (auto x : a) {
                  ok1 &= x % 2 == 0;
                  ok2 &= x % 2 == 1;
            }
            if (ok1 || ok2) {
                  cout << "YES\n";
                  continue;
            }
            // int64_t gg = 0;
            // for (auto x : a) gg = __gcd(gg, x);
            // if (gg != 1) cout << "YES\n";
            // else {
            //       int ct = count(a.begin(), a.end(), 0LL);
            //       bool okx = true;
            //       okx &= ct == 0;
            //       map <int64_t, int> bb;
            //       for (auto x : a) bb[x]++;
            //       map <int64_t, int> done;
            //       for (int i = n - 1; i >= 0; --i) {
            //             if (a[i] == 1) continue;
            //             if (done[a[i]]) continue;
            //             if (bb[a[i] - 1]) okx = false;
            //       }
            //       for (auto &x : a) x %= 3;
            //       sort(a.begin(), a.end());
            //       if (a[0] == a.back()) {
            //             cout << "YES\n";
            //             continue;
            //       }
            //       for (auto &x : a) x %= 2;
            //       sort(a.begin(), a.end());
            //       if (a[0] == a.back()) {
            //             cout << "YES\n";
            //             continue;
            //       }
            //       cout << (okx ? "YES\n" : "NO\n");
            // }
            int ct = count(a.begin(), a.end(), 1LL);
            if (ct == 0) cout << "YES\n";
            else {
                  int ct1 = count(a.begin(), a.end(), 0LL);
                  bool okx = true;
                  okx &= ct1 == 0;
                  map <int64_t, int> bb;
                  for (auto x : a) bb[x]++;
                  map <int64_t, int> done;
                  for (int i = n - 1; i >= 0; --i) {
                        if (a[i] == 1) continue;
                        if (done[a[i]]) continue;
                        if (bb[a[i] - 1]) okx = false;
                        done[a[i]]++;
                  }
                  for (auto &x : a) x %= 3;
                  sort(a.begin(), a.end());
                  if (a[0] == a.back()) {
                        cout << "YES\n";
                        continue;
                  }
                  for (auto &x : a) x %= 2;
                  sort(a.begin(), a.end());
                  if (a[0] == a.back()) {
                        cout << "YES\n";
                        continue;
                  }
                  cout << (okx ? "YES\n" : "NO\n");
            }
      }
}