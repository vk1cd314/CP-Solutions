#include <bits/stdc++.h>

using namespace std;

int main(){
    int k; cin >> k;
    int a, b; cin >> a >> b;
    bool found = false;

    for (int i = a; i <= b; ++i) {
        if (i % k == 0) found = true;
    }

    puts((found) ? "OK" : "NG");
    return 0;
}