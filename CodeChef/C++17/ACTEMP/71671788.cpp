#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t; cin >> t;
	while (t--) {
	    int a, b, c; cin >> a >> b >> c;
	    if (b >= a and b >= c) cout << "Yes\n";
	    else cout << "No\n";
	}
	return 0;
}
