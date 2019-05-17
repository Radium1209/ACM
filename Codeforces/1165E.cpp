#include <cstdio>
#include <iostream>
#include <algorithm>
typedef long long ll;
const ll MOD=998244353;
using namespace std;

int n;
ll a[200005],b[200005],ans=0;

int main()
{
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        scanf("%I64d",&a[i]);
        a[i]=a[i]*(ll)(n-i+1)*(ll)i;
    }
    for (int i=1;i<=n;i++)
        scanf("%I64d",&b[i]);
    sort(a+1,a+1+n);
    sort(b+1,b+1+n,greater<ll>());
    for (int i=1;i<=n;i++)
        ans=(ans+((a[i]%MOD)*(b[i]%MOD))%MOD)%MOD;
    cout << ans << endl;
    return 0;
}
