#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif

using namespace std;

const int N = 3e3 + 33;
int F[N][N];
string s, t; 

int rec(int i, int j) {
      if (i == (int) s.size() || j == (int) t.size()) return 0;

      int &ret = F[i][j];
      if (~ret) return ret;

      if (s[i] == t[j]) ret = rec(i + 1, j + 1) + 1;
      else ret = max(rec(i + 1, j), rec(i, j + 1));

      return ret;
}

void print(int i, int j) {
      if (i == (int) s.size() || j == (int) t.size()) return;

      if (s[i] == t[j]) {
            if (rec(i, j) == rec(i + 1, j + 1) + 1) {
                  cout << s[i];
                  print(i + 1, j + 1);
            }
      } else {
            if (rec(i, j) == rec(i + 1, j)) print(i + 1, j);
            else if (rec(i, j) == rec(i, j + 1)) print(i, j + 1);
      }
}

int main() {
      #ifdef Icry
            auto begin = std::chrono::high_resolution_clock::now();
      #endif
      ios_base :: sync_with_stdio(0);
      cin.tie(0);

      cin >> s >> t;
      memset(F, -1, sizeof F);
      print(0, 0);

      #ifdef Icry
            auto end = std::chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << std::chrono::duration_cast <std::chrono::duration <double>>(end - begin).count() << " seconds]\n";  
      #endif
}