#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif

using namespace std;

int main() {
      #ifdef Icry
            auto begin = chrono :: high_resolution_clock :: now();
      #endif
      ios_base :: sync_with_stdio(0);
      cin.tie(0);

      int a[3]; cin >> a[0] >> a[1] >> a[2];
      sort(a, a + 3);
      if (a[0] == a[1]) cout << a[2] << '\n';
      else if (a[1] == a[2]) cout << a[0] << '\n';
      else if (a[0] == a[2]) cout << a[1] << '\n';
      else cout << "0\n";
      #ifdef Icry
            auto end = chrono :: high_resolution_clock :: now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono :: duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}