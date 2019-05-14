#include <cstdio>
#include <iostream>
typedef long long ll;
const int MOD=100003;
using namespace std;

ll quick_pow(ll x,ll n)
{
    ll ret=1LL;
    while(n)
    {
        if (n&1) ret=(ret*x)%MOD;
        x=(x*x)%MOD;
        n>>=1;
    }
    return ret;
}

int main()
{
    ll m,n,ans;
    cin >> m >> n;
    ans=(quick_pow(m,n)-(m*quick_pow(m-1,n-1)%MOD))%MOD;
    if (ans<0) ans+=MOD;
    cout << ans << endl;
    return 0;
}
