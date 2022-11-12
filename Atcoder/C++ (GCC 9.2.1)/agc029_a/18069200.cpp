#include <bits/stdc++.h>

using namespace std;

#ifdef BOI
#include "debug.h"
#else
#define debug(args...)
#endif

int main() {
      ios_base :: sync_with_stdio(0);
      cin.tie(0);

      string s; cin >> s;

      long long curr = 0, cnt = 0;
      for (int i = 0; i < (int) s.size(); ++i) {
            if (s[i] == 'W') {
                  cnt += i - curr;
                  ++curr;
            }
      }      
      
      cout << cnt << endl;
}
