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

      int n; cin >> n;
      string s; cin >> s;

      vector <int> cA(n), cT(n), cC(n), cG(n);
      for (int i = 0; i < n; ++i) {
            if (i == 0) {
                  cA[0] = (s[i] == 'A');
                  cT[0] = (s[i] == 'T');
                  cC[0] = (s[i] == 'C');
                  cG[0] = (s[i] == 'G');
            } else {
                  cA[i] = cA[i - 1] + (s[i] == 'A');
                  cT[i] = cT[i - 1] + (s[i] == 'T');
                  cC[i] = cC[i - 1] + (s[i] == 'C');
                  cG[i] = cG[i - 1] + (s[i] == 'G');
            }
      }      

      debug(cA, cT, cC, cG);
      int cnt = 0;
      for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                  if (i != 0) {
                        int ctA = cA[j] - cA[i - 1];
                        int ctT = cT[j] - cT[i - 1];
                        int ctC = cC[j] - cC[i - 1];
                        int ctG = cG[j] - cG[i - 1];
                        if (ctA == ctT && ctC == ctG) ++cnt;
                  } else {
                        int ctA = cA[j];
                        int ctT = cT[j];
                        int ctC = cC[j];
                        int ctG = cG[j];
                        if (ctA == ctT && ctC == ctG) ++cnt;
                  }
                  
            }
      }

      cout << cnt << endl;
}
