#include <cstdio>
#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

int main() {
    ll ans=0,n;
    cin >> n;
    if (n==1) ans=1;
    else if (n==2) ans=2;
    else {
        ll GCD=__gcd(n,n-2);
        ans=(n/GCD)*(n-1)*((n-2)/GCD);
        GCD=__gcd(n-1,n-3);
        ans=max(((n-1)/GCD)*(n-2)*((n-3)/GCD),ans);
        GCD=__gcd(n,n-3);
        ans=max(((n)/GCD)*(n-1)*((n-3)/GCD),ans);
    }
    cout << ans << endl;
    return 0;
}
