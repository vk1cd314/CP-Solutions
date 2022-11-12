#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif

using namespace std;

const int N = 1e5 + 10;
const int mod = 1e9 + 7;

int dp[10][N], n;
string s;
string need = "chokudai";

int rec(int i, int j) {
      if (j == n) return 0;

      int &ret = dp[i][j];
      if (~ret) return ret;

      ret = rec(i, j + 1);
      if (need[i] == s[j]) {
            if (i == 7) ret = (ret + 1) % mod;
            else ret = (ret + rec(i + 1, j + 1)) % mod;
      }

      return ret;
}

int main() {
      #ifdef Icry
            auto begin = chrono::high_resolution_clock::now();
      #endif
      ios_base::sync_with_stdio(0);
      cin.tie(0);

      cin >> s;
      n = s.length();
      
      memset(dp, -1, sizeof dp);

      cout << rec(0, 0) << '\n';

      #ifdef Icry
            auto end = chrono::high_resolution_clock::now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono::duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}