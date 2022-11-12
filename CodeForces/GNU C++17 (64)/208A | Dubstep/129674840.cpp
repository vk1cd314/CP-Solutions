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
 
      string s; cin >> s;
      int id = s.find("WUB");
      while (id != -1) {
            s.insert(s.begin() + id, ' ');
            s.erase(s.begin() + id + 1, s.begin() + id + 4);
            id = s.find("WUB");
      }
      while (s[0] == ' ') s.erase(s.begin());
      while (s.back() == ' ') s.pop_back();
      cout << s[0];
      for (int i = 1; i < (int) s.size(); ++i) {
            if (s[i] == s[i - 1] && s[i] == ' ') continue;
            cout << s[i];
      }
}