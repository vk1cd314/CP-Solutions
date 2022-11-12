#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif

using namespace std;

const double PI = acos(-1);

int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);

      int a, b, d; cin >> a >> b >> d;
      vector <vector <double>> v(2, vector <double>(2, 0));
      double dd = d * PI / 180.0;
      v[0][0] = cos(dd);
      v[0][1] = -sin(dd);
      v[1][0] = sin(dd);
      v[1][1] = cos(dd);
      cout << fixed << setprecision(10);
      cout << v[0][0] * a + v[0][1] * b << ' ' << v[1][0] * a + v[1][1] * b << '\n';
}