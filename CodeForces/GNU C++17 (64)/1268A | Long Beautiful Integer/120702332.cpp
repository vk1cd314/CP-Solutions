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
 
      int n, k; cin >> n >> k;
      string s; cin >> s;
      string curr = s.substr(0, k);
      string tmp = curr;
      while (curr.size() < s.size()) curr += tmp;
      while (curr.size() > s.size()) curr.pop_back();
 
      cout << n << '\n';
      if (curr >= s) {
            cout << curr << '\n';
      } else {
            reverse(tmp.begin(), tmp.end());
            for (int i = 0; i < k; ++i) {
                  if (tmp[i] != '9') {
                        tmp[i]++;
                        break;
                  } else tmp[i] = '0';
            }
            reverse(tmp.begin(), tmp.end());
            debug(tmp);
            string ans = tmp;
            while (ans.size() < s.size()) ans += tmp;
            while (ans.size() > s.size()) ans.pop_back();
            cout << ans << '\n';
      }
 
      #ifdef Icry
            auto end = chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono::duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}