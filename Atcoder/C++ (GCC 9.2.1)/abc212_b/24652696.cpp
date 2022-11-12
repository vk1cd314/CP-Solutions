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

      int a, b; cin >> a >> b;
      if (a > 0 && b > 0) cout << "Alloy\n";
      else if (a == 0 && b > 0) cout << "Silver\n";
      else if (b == 0 && a > 0) cout << "Gold\n";
      else assert(false);

      #ifdef Icry
            auto end = chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono::duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}