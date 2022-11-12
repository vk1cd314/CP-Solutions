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
 
      int q; cin >> q;
      auto brute = [&](int x) {
            int ret = 0;
            for (int i = 1; i < x; ++i) {
                  ret = max(ret, __gcd(x ^ i, x & i));
            }
            // vector <int> hmmm;
            // for (int i = 1; i < x; ++i) {
            //       int lel = __gcd(x ^ i, x & i);
            //       if (lel == ret) hmmm.push_back(i);
            // }
            // debug(hmmm);
            return ret;
      };
      // debug(brute((1 << 25) - 1));
      vector <pair <int, int>> dud = {{3, 1}, {4, 7}, {7, 1}, {8, 15}, {15, 5}, {16, 31}, {31, 1}, {32, 63}, {63, 21}, {64, 127}, {127, 1}, {128, 255}, {255, 85}, {256, 511}, {511, 73}, {512, 1023}, {1023, 341}, {1024, 2047}, {2047, 89}, {2048, 4095}, {4095, 1365}, {4096, 8191}, {8191, 1}, {8192, 16383}, {16383, 5461}, {16384, 32767}, {32767, 4681}, {32768, 65535}, {65535, 21845}, {65536, 131071}, {131071, 1}, {131072, 262143}, {262143, 87381}, {262144, 524287}, {524287, 1}, {524288, 1048575}, {1048575, 349525}, {1048576, 2097151}, {2097151, 299593}, {2097152, 4194303}, {4194303, 1398101}, {4194304, 8388607}, {8388607, 178481}, {8388608, 16777215}, {16777215, 5592405}, {16777216, 33554431}, {33554431, 1082401}};
      map <int, int> lul;
      for (int i = 0; i < (int) dud.size(); ++i) {
            lul[dud[i].first] = dud[i].second;
      }
      debug(1 << 25);
      debug(lul);
      // 3 wrong submissions for not considering 2 ^ 25 - 1 
      // F
      for (int i = 1; i <= q; ++i) {
            int qq; cin >> qq;
            // if (i == 196) {
            //       cout << qq << '\n';
            //       assert(false);
            // }
            if (qq < 3) {
                  cout << "3\n";
                  continue;
            }
            // int dd = brute(qq);
            // debug(dd);
            if (lul[qq] != 0) cout << lul[qq] << '\n';
            else {
                  int ded = 1;
                  while (ded <= qq) ded *= 2;
                  // assert(ded - 1 == brute(qq));
                  cout << ded - 1 << '\n';
            }
      }
      // for (int i = 2; i <= 100000; ++i) {
      //       if (lul[i] == 0) {
      //             int ded = 1;
      //             while (ded <= i) ded *= 2;
      //             assert(ded - 1 == brute(i));
      //       }
      // }
 
 
      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}