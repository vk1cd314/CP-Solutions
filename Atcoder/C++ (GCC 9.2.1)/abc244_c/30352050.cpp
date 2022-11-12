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

      int n; cin >> n;
      set <int> s;
      for (int i = 1; i <= 2 * n + 1; ++i) s.insert(i);
      while (true) {
            cout << *s.begin() << endl;
            s.erase(s.begin());
            int in; cin >> in;
            if (in == 0) break;
            s.erase(in);
      }
}