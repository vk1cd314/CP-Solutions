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
 
      int b, k; cin >> b >> k;
      vector <int> a(k); for (int &x : a) cin >> x;
      if (b % 2 == 0) {
            if (a.back() % 2) cout << "odd\n";
            else cout << "even\n";
      } else {
            int c1 = 0;
            for (int x : a) c1 += (x % 2);
            cout << (c1 % 2 ? "odd\n" : "even\n");
      }
 
      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}