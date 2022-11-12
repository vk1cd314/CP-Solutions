#include<bits/stdc++.h>
#define ll long long int 
using namespace std;

int main()
{
  ll x; cin >> x;
  
  if(x<500) cout << (x/5)*5;
  else {
    ll y = (x/500)*1000;
    x=x-y/2;
    cout << y+(x/5)*5 ;
  }
  
}
