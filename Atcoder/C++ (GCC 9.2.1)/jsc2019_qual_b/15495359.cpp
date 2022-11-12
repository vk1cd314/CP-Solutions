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

const ll mod = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  #ifdef BOI
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  ll n, k; cin >> n >> k;
  vector<ll> a(n);
  ll ans = 0;
  // map<ll, ll> inc;
  for(ll& it : a) cin >> it;
  for(ll i = 0; i < n; ++i) {
    ll temp = 0;
    for(ll j = i + 1; j < n; ++j) {
      temp += a[i] > a[j];
    }
    // temp = (temp*k)%mod;
    // temp = (temp*(k + 1))%mod;
    // temp = (temp/2)%mod;
    ll ntemp = ((k*(k + 1))/2)%mod;
    temp = (ntemp*temp)%mod;
    debug(temp);
    ans = (ans + temp)%mod;
    temp = 0;
    for(ll j = 0; j < i; ++j) {
      temp += a[i] > a[j];
    }
    // temp = (temp*k)%mod;
    // temp = (temp*(k - 1))%mod;
    // temp = (temp/2)%mod;
    ll xtemp = ((k*(k - 1))/2)%mod;
    temp = (xtemp*temp)%mod;
    debug(temp);
    ans = (ans + temp)%mod;
  }
  // debug(inc);
  // for(auto it : inc) {
  //   ll temp = k;
  //   temp = (temp*(k - 1))%mod;
  //   temp = (temp/2)%mod;
  //   ans = (ans + temp)%mod;
  // }
  cout << ans;
  return 0;
}