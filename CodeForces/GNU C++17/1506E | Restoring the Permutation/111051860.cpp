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
            int n; cin >> n;
            map <int, int> no, no1;
            vector <int> q(n); for (int &x : q) cin >> x, no[x]++, no1[x]++;
            vector <int> mi(n), mx(n);
            // priority_queue <int> ducc;
            set <int> ducc;
            for (int i = 1; i <= n; ++i) if (no1[i] == 0) ducc.insert(i);
            int lst1 = 1, lst2 = n;
            for (int i = 0; i < n; ++i) {
                  int j = i;
                  mi[i] = q[i];
                  mx[i] = q[i];
                  while (j + 1 < n && q[j] == q[j + 1]) {
                        while (no[lst1] && lst1 < q[j]) ++lst1;
                        mi[j + 1] = lst1; no[lst1]++;
                        auto it = ducc.lower_bound(q[j] - 1);
                        if (it == ducc.end() || *it > q[j] - 1) --it;
                        mx[j + 1] = *it;
                        ducc.erase(it); 
                        ++j;
                  }
                  i = j;
            }
            debug(mi);
            debug(mx);
            for (int x : mi) cout << x << ' ';
            cout << '\n';
            for (int x : mx) cout << x << ' ';
            cout << '\n';
      }
 
      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}