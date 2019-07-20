#include <cstdio>
#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

ll a,b,c,ans;

int main()
{
    cin >> a >> b >> c;
    ans=c*2LL;
    if (a==b)
        ans=ans+a+b;
    else
        ans=ans+2LL*min(a,b)+1LL;
    cout << ans << endl;
    return 0;
}
