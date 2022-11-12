#include <bits/stdc++.h>

using namespace std;

vector <vector <int>> res;
vector <int> curr;
int n, m;
void rec(int x) {
    if (curr.size() == n) {
        res.push_back(curr);
        return;
    }
    for (int i = x; i <= m; ++i) {
        curr.push_back(i);
        rec(i + 1);
        curr.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    rec(1);
    sort(res.begin(), res.end());
    for (auto v : res) {
        for (int x : v) cout << x << ' ';
        cout << '\n';
    }
}