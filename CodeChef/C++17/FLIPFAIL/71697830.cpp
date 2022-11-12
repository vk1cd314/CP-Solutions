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
            string s; cin >> s;
            int n = s.size();
            int on = count(s.begin(), s.end(), '1');
            vector <int> pf1(n + 1), sf1(n + 1), pf0(n + 1);
            pf1[0] = (s[0] != '1');
            for (int i = 1; i < n; ++i) {
                  pf1[i] = pf1[i - 1];
                  if (s[i] != '1') pf1[i]++;
            }
            pf1[n] = pf1[n - 1];
            sf1[n - 1] = (s[n - 1] != '1');
            for (int i = n - 2; i >= 0; --i) {
                  sf1[i] = sf1[i + 1];
                  if (s[i] != '1') sf1[i]++;
            }
            sf1[n] = sf1[n - 1];
            pf0[0] = (s[0] != '0');
            for (int i = 1; i < n; ++i) {
                  pf0[i] = pf0[i - 1];
                  if (s[i] != '0') pf0[i]++;
            }
            pf0[n] = pf0[n - 1];
            debug(pf1, sf1, pf0);
            int ans = INT_MAX;
            for (int i = 0; i <= on; ++i) {
                  int ed = on - i;
                  int sId = i - 1, eId = n - ed;
                  int tot = 0;
                  if (sId < 0 && eId == n) tot = 0;
                  else if (sId < 0) tot = sf1[eId];
                  else if (eId == n) tot = pf1[sId];
                  else tot = pf1[sId] + sf1[eId];
                  debug(sId, eId);
                  int l = sId + 1, r = eId - 1;
                  if (l <= r) {
                        tot += pf0[r];
                        if (l) tot -= pf0[l - 1];
                  }
                  debug(tot);
                  assert(tot % 2 == 0);
                  ans = min(ans, tot / 2);
            }
            cout << ans << '\n';
      }
}