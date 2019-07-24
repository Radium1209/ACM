#include <cstdio>
#include <iostream>
typedef unsigned long long ll;
const ll MOD=998244353;
using namespace std;

ll n,x,ans=0;

ll merge(ll x,ll y) {
    ll ret=0,t=1;
    while(t<x) {
        t*=10;
    }
    while(t) {
        ret=ret*10+x/t;
        ret=ret*10+y/t;
        x%=t; y%=t;
        t/=10;
    }
    return ret%MOD;
}

int main() {
    cin >> n;
    for (int i=1;i<=n;i++) {
        cin >> x;
        ans=(ans+(merge(x,x)*n%MOD))%MOD;
    }
    cout << (ans+MOD)%MOD << endl;
    return 0;
}
