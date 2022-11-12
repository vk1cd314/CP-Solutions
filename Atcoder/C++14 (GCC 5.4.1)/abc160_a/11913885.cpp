#include <bits/stdc++.h>
#define ll long long int
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s; cin >> s;
    
    if(s[2] == s[3] && s[4] == s[5]) cout << "Yes";
    else cout << "No";
 
    return 0;
}