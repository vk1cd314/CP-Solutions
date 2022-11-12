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
 
      srand(time(0));
 
      auto gen = [&](int n) {
            vector <int> ret(n + 1, 0);
            iota(ret.begin(), ret.end(), 0);
            int rng = rand() % 5 + 1;
            while (rng--) {
                  random_shuffle(ret.begin() + 1, ret.end());
            } 
            return ret;
      };
 
      int t; cin >> t;
      while (t--) {
            int n; cin >> n;
            #ifdef Icry
            vector <int> p(n + 1);
            p = gen(n);
            debug(p);
            #endif
            auto query = [&](int i) {
                  cout << "? 2 " << i << ' ' << i + 1 << " 1" << endl;
                  int x; cin >> x;
                  #ifdef Icry
                  x = min(max(1, p[i]), max(2, p[i + 1]));
                  #endif
                  if (x == 1) return i;
                  if (x == 2) {
                        cout << "? 2 " << i + 1 << ' ' << i << " 1" << endl;
                        cin >> x;
                        #ifdef Icry
                        x = min(max(1, p[i + 1]), max(2, p[i]));
                        #endif
                        if (x == 1) return i + 1; 
                  }
                  return -69;
            };
 
            int mi = n;
            for (int i = 1; i + 1 <= n; i += 2) {
                  int hmm = query(i);
                  if (hmm != -69) {
                        mi = hmm;
                        break;
                  }
            }
 
            vector <int> a(n + 1);
            for (int i = 1; i <= n; ++i) {
                  if (i != mi) {
                        cout << "? 1 " << mi << ' ' << i << ' ' << n - 1 << endl;
                        int val; cin >> val;
                        #ifdef Icry
                        val = max(min(n - 1, p[mi]), min(n, p[i]));
                        #endif
                        a[i] = val;
                  }
            }
 
            a[mi] = 1;
            #ifdef Icry
            assert(a == p);
            #endif
            cout << "! ";
            for (int i = 1; i <= n; ++i) cout << a[i] << ' ';
            cout << endl;
      }
 
      #ifdef Icry
            auto end = chrono :: high_resolution_clock :: now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono :: duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}
// 3 1 4 2