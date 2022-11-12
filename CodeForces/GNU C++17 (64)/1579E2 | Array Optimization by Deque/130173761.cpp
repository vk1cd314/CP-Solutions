#ifdef Icry
#include "debug.h"
#else
#include <bits/stdc++.h>
#define debug(args...) 
#endif
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
template <typename num_t>
using ordered_set = tree<num_t, null_type, less<num_t>, rb_tree_tag, tree_order_statistics_node_update>;
 
template <typename num_t>
struct ordered_multiset {
      ordered_set<pair<num_t, int>> vals;
      set<pair<num_t, int>> best; 
 
      int findbest(num_t val) {
            return (*best.upper_bound(make_pair(val - 1, 0))).second;
      }
 
      bool contains(num_t val) {
            return vals.find(make_pair(val, -1)) != vals.end();
      }
 
      void insert(num_t val) {
            if (contains(val)) {
                  int loc = findbest(val);
                  best.erase(make_pair(val, loc));
                  best.insert(make_pair(val, loc - 1));
                  vals.insert(make_pair(val, loc - 1));
            } else { 
                  best.insert(make_pair(val, -1));
                  vals.insert(make_pair(val, -1));
            }
      }
 
      void erase(num_t val) {
            if (!contains(val)) return;
            num_t loc = findbest(val);
 
            best.erase(make_pair(val, loc));
            vals.erase(make_pair(val, loc));
            if (loc != -1) best.insert(make_pair(val, loc + 1)); 
      }
 
      num_t find_by_order(int k) { return (*vals.find_by_order(k)).first; } // no pointer direct value
      int order_of_key(num_t k) { return vals.order_of_key(make_pair(k - 1, 0)); }
      auto begin() { return vals.begin(); }
      auto end() { return vals.end(); }
      auto rbegin() { return vals.rbegin(); }
      auto rend() { return vals.rend(); }
      int size() { return vals.size(); }
      bool empty() { return (int) vals.size() == 0; }
      void clear() {
            vals.clear();
            best.clear();
      }
      int count(num_t k) { return vals.order_of_key({k, 0}) - vals.order_of_key({k - 1, 0}); }
      auto lower_bound(num_t k) { return vals.lower_bound(make_pair(k - 1, 0)); }
      auto upper_bound(num_t k) { return vals.upper_bound(make_pair(k, 0)); }
};
 
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
 
      int t; cin >> t;
      while (t--) {
            int n; cin >> n;
            deque <int> d;
            ordered_multiset<int> ms;
            int64_t ans = 0;
            for (int i = 0; i < n; ++i) {
                  int x; cin >> x;
                  if (d.empty()) d.push_back(x), ms.insert(x);
                  else {
                        int key = ms.order_of_key(x);
                        int key1 = ms.order_of_key(x + 1);
                        if (key > ms.size() - key1) ans += ms.size() - key1;
                        else ans += key;
                        ms.insert(x);
                  }
            }
            cout << ans << '\n';
      }     
}