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

      vector <string> s1(4);
      for (auto &ss : s1) cin >> ss;

      vector <string> s2 = { "H", "2B", "3B", "HR" };
      sort(s1.begin(), s1.end());
      sort(s2.begin(), s2.end());
      cout << (s1 == s2 ? "Yes\n" : "No\n");

      #ifdef Icry
            auto end = chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono::duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}