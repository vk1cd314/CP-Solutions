// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#ifdef BOI
#include "debug.h"
#else
#define debug(args...)
#endif
#define endl '\n'
using ll = long long;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  ll n; cin >> n;
  if(n&1) {
    cout << "0";
  } else {
    ll ans = 0;
    n /= 2;
    while(n != 0) {
      ans += n/5;
      n /= 5;
    }
    cout << ans;
  }
  return 0;
}