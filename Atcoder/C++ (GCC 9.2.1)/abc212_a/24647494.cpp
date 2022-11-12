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

      string s; cin >> s;
      if (s[0] == s[1] && s[1] == s[2] && s[2] == s[3]) cout << "Weak\n";
      else {
            int x[4];
            x[0] = s[0] - '0';
            x[1] = s[1] - '0';
            x[2] = s[2] - '0';
            x[3] = s[3] - '0';
            if (x[1] == (x[0] + 1) % 10 && x[2] == (x[1] + 1) % 10 && x[3] == (x[2] + 1) % 10) cout << "Weak\n";
            else cout << "Strong\n";
      }

      #ifdef Icry
            auto end = chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono::duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}