#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
const int N = 2e5 + 10;
int dp[100][N];
int n;
vector <int> a;
 
int rec(int i, int sum) {
      if (sum < 0) return 0;
      if (i == n) {
            return sum == 0;
      }
 
      int &ret = dp[i][sum];
      if (~ret) return ret;
 
      ret = 0;
      ret |= rec(i + 1, sum);
      ret |= rec(i + 1, sum - a[i]);
 
      return ret;
}
 
int main() {
      #ifdef Icry
            auto begin = chrono :: high_resolution_clock :: now();
      #endif
      ios_base :: sync_with_stdio(0);
      cin.tie(0);
 
      cin >> n;
      int sum = 0;
      a.assign(n, 0);
      for (int &x : a) cin >> x, sum += x;
 
      if (sum & 1) {
            cout << "0\n";
            return 0;
      }
 
      memset(dp, -1, sizeof dp);
      if (rec(0, sum / 2)) {
            int id = -1;
            int mn = INT_MAX;
            for (int x : a) mn = min(mn, __builtin_ctz(x));
            mn = 1 << mn;
            for (int i = 0; i < n; ++i) {
                  if (a[i] % 2) {
                        id = i + 1;
                        break;
                  }
            }
 
            if (id != -1) {
                  cout << "1\n";
                  cout << id << '\n';
                  return 0;
            }
 
            int mi = INT_MAX;
            for (int i = 0; i < n; ++i) {
                  int cnt = 0;
                  while (a[i] % 2 == 0) ++cnt, a[i] /= 2;
                  if (cnt < mi) {
                        id = i + 1;
                        mi = cnt;
                  }
            }
 
            cout << "1\n";
            cout << id << '\n';
 
            return 0;
      } 
 
      cout << "0\n";
 
      #ifdef Icry
            auto end = chrono :: high_resolution_clock :: now();
            cerr << setprecision(4) << fixed;
            cerr << "[Execution time: " << chrono :: duration_cast <chrono :: duration <double>> (end - begin).count() << " seconds]\n";  
      #endif
}