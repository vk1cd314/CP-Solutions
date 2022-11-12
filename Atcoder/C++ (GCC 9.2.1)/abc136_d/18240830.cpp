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

      string s;cin >> s;
      int n = s.length();
      
      vector <pair<char, int>> gr;
      gr.push_back({s[0], 0});

      for (int i = 0; i < n; ++i) {
            if (s[i] == gr.back().first) gr.back().second++;
            else gr.push_back({s[i], 1});
      }

      debug(gr);
      assert(gr.size() % 2 == 0);

      int id = 0;
      vector <int> out(n, 0);
      for (int i = 0; i + 1 < n; ++i) {
            if (s[i] == 'R' && s[i + 1] == 'L') {
                  int cnt = gr[id].second + 1 >> 1;
                  int cnt1 = gr[id + 1].second + 1 >> 1;
                  out[i] = cnt + gr[id + 1].second - cnt1;
                  out[i + 1] = cnt1 + gr[id].second - cnt;
                  id += 2;
            }
      }
      
      for (int i = 0; i < n; ++i) cout << out[i] << ' ';
}
