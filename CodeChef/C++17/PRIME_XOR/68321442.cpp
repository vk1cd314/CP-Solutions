#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif

using namespace std;

int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);

      int t; cin >> t;
      while (t--) {
            long long x, y; cin >> x >> y;
            if (x % 2 == 1 && y % 2 == 1) {
                  // b = 2
                  long long b = 2;
                  long long c = y ^ 2;
                  long long a = x ^ 2;
                  vector <long long> v = {a, b, c};
                  sort(v.begin(), v.end());
                  for (int x : v) cout << x << ' ';
                  cout << '\n';
            } else if (x % 2 == 1) {
                  // a = 2;
                  long long z = x ^ y;
                  long long a = 2;
                  long long b = x ^ 2;
                  long long c = z ^ 2;
                  vector <long long> v = {a, b, c};
                  sort(v.begin(), v.end());
                  for (int x : v) cout << x << ' ';
                  cout << '\n';
            } else if (y % 2 == 1) {
                  // c = 2;
                  long long z = x ^ y;
                  long long c = 2;
                  long long b = y ^ 2;
                  long long a = z ^ 2;
                  vector <long long> v = {a, b, c};
                  sort(v.begin(), v.end());
                  for (int x : v) cout << x << ' ';
                  cout << '\n';
            } else assert(false);
      }
}