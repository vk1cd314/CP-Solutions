#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...)
#endif
 
using namespace std;
 
#define ll long long
// #define double long double
 
typedef complex<double> base;
#define PI acos(-1)
void fft(vector<base> &a, bool invert) {
  int n = (int)a.size();
  for (int i = 1, j = 0; i < n; ++i) {
    int bit = n >> 1;
    for (; j >= bit; bit >>= 1) j -= bit;
    j += bit;
    if (i < j) swap(a[i], a[j]);
  }
  for (int len = 2; len <= n; len <<= 1) {
    double ang = 2 * PI / len * (invert ? -1 : 1);
    base wlen(cos(ang), sin(ang));
    for (int i = 0; i < n; i += len) {
      base w(1);
      for (int j = 0; j < len / 2; ++j) {
        base u = a[i + j], v = a[i + j + len / 2] * w;
        a[i + j] = u + v;
        a[i + j + len / 2] = u - v;
        w *= wlen;
      }
    }
  }
  if (invert) for (int i = 0; i < n; ++i) a[i] /= n;
}
vector <int> multiply(const vector<int> &a, const vector<int> &b) {
  vector<base> fa(a.begin(), a.end()), fb(b.begin(), b.end());
  size_t n = 1;
  while (n < max(a.size(), b.size())) n <<= 1;
  n <<= 1;
  fa.resize(n), fb.resize(n);
  fft(fa, false), fft(fb, false);
  for (size_t i = 0; i < n; ++i) fa[i] *= fb[i];
  fft(fa, true);
  vector <int> res(n);
  for (size_t i = 0; i < n; ++i) res[i] = int(fa[i].real() + 0.5);
  for (size_t i = 0; i < n; ++i) res[i] > 0 ? res[i] = 1 : 69;
  while (res.size() > 1 && res.back() == 0) res.pop_back();
  return res;
}
vector <int> bp(vector <int> a, int p) {
  vector <int> res = {1};
  while (p) {
    if (p & 1) res = multiply(res, a);
    a = multiply(a, a);
    p >>= 1;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
 
  vector <int> f(1002, 0);
  int n, k; cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    f[x] = 1;
  }
  auto res = bp(f, k);
  for (int i = 0; i < (int) res.size(); ++i) {
    if (res[i]) {
      cout << i << ' ';
    }
  }
}