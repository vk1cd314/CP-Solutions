#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 
 string t, p; cin >> t >> p;
 int n = t.size();
 vector <int> a(n); for (int &x : a) cin >> x, --x;
 int l = 0, r = n;
 auto can = [&](int x) {
  string nw = "";
  vector <bool> bad(n, true); 
  for (int i = 0; i < x; ++i) bad[a[i]] = false;
  for (int i = 0; i < n; ++i) if (bad[i]) nw += t[i];
  int i = 0, j = 0;
  int sz = nw.size();
  if (sz < (int) p.size()) return false;
  int match = 0;
  // cerr << "Can " << x << ' ' << nw << '\n';
  while (i < sz && j < (int) p.size()) {
   if (nw[i] == p[j]) ++i, ++j, ++match;
   else i++;
  }
  return match == (int) p.size();
 };
 while (r - l > 1) {
  int m = l + r >> 1;
  // cerr << m << '\n';
  if (can(m)) l = m;
  else r = m;
  // cerr << l << ' ' << r << '\n';
 }
 cout << l << '\n';
}