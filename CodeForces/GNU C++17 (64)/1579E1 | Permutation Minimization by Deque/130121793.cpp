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
            deque <int> q;
            for (int i = 0; i < n; ++i) {
                  int x; cin >> x;
                  if (q.empty()) q.push_back(x);
                  else {
                        if (x < q.front()) q.push_front(x);
                        else q.push_back(x);
                  }
            }
            for (int x : q) cout << x << ' ';
            cout << '\n';
      }
}