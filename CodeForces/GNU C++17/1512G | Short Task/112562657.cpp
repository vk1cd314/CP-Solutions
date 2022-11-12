#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
const int N = 1e7 + 2;
int divs[N + 1], cnt[N + 1];
 
int main() {
      #ifdef Icry
            auto begin = std::chrono::high_resolution_clock::now();
      #endif
      ios_base :: sync_with_stdio(0);
      cin.tie(0); 
      
      memset(cnt, -1, sizeof cnt);
      for (int i = 1; i <= N; ++i) {
            for (int j = i; j <= N; j += i) {
                  divs[j] += i;
            }
            if (divs[i] <= N && cnt[divs[i]] == -1) cnt[divs[i]] = i;
      }
 
      // debug(divs);
      // set <pair <int, int>> st;
      // for (int i = 1; i <= N; ++i) st.insert({divs[i], i});
 
      int t; cin >> t;
      // vector <int> no;
      while (t--) {
            int64_t c; cin >> c;
            // bool sex = true;
            // for (int i = 1; i <= c; ++i) {
            //       // int64_t sum = 0;
            //       vector <int64_t> divs;
            //       for (int j = 1; j * j <= i; ++j) {
            //             if (i % j == 0) {
            //                   if (j != i / j) divs.push_back(i / j);
            //                   divs.push_back(j);
            //             }
            //       }
            //       sort(divs.begin(), divs.end());
            //       int64_t sum = 0;
            //       for (auto ded : divs) sum += ded;
            //       // debug(divs, i);
            //       if (sum == c) {
            //             // debug(divs, i, c);
            //             sex = false;
            //             break;
            //       }
            // }     
            // if (sex) {
            //       no.push_back(c);
            //       // debug(33, c);
            // }
            // auto it = st.lower_bound({c, 0});
            // if (it == st.end() || (*it).first != c) cout << "-1\n";
            // else cout << (*it).second << '\n';
            cout << cnt[c] << '\n';
      }
      // debug(no);
 
      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}