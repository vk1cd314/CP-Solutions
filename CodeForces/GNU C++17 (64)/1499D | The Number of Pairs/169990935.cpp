#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
using namespace std;
 
#define ll long long
 
const int N = 2e7 + 10;
int spf[N];
 
void sieve() {      
      for (int i = 2; i < N; ++i) {
            if (!spf[i]) {
                  for (int j = i; j < N; j += i) {
                        spf[j] = i;
                  }
            }
      }
}
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      sieve();
 
      int t; cin >> t;
      while (t--) {
            ll c, d, x; cin >> c >> d >> x;
            auto factorize = [](ll x) {
                  vector <ll> ret;
                  for (int i = 1; i * i <= x; ++i) {
                        if (x % i == 0) {
                              ret.push_back(i);
                              if (i != x / i) ret.push_back(x / i);
                        }
                  }
                  return ret;
            };
 
            auto brute = [](ll x) {
                  ll ret = 0;
                  for (int i = 1; i * i <= x; ++i) {
                        if (x % i == 0) {
                              ll a = i, b = x / i;
                              if (gcd(a, b) == 1) {
                                    ret++;
                                    if (a != b) ret++; 
                              }
                        }
                  }
                  return ret;
            };
 
            auto cpCount = [](ll x) {
                  ll ret = 0;
                  while (x > 1) {
                        ll div = spf[x];
                        while (x % div == 0) x /= div;
                        ret++;
                  }
                  return ret;
            };
 
            ll ans = 0;
            auto facs = factorize(x);
            for (auto g : facs) {
                  // a * b = prod st gcd(a, b) = g
                  // a / g * b / g = prod / (g * g) st gcd(a / g, b / g) = 1
                  ll prod = x / g + d;
                  if (prod % c) continue;
                  prod /= c;
                  assert(prod < (int) 2e7 + 10);
                  ans += 1ll << cpCount(prod);
            }
            cout << ans << '\n';
      }
}