#include <cstdio>
#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

int t,n;
ll d[305],ans,sum=0;

int main()
{
    cin >> t;
    while(t--)
    {
        cin >> n;
        for (int i=1;i<=n;i++)
            cin >> d[i];
        sort(d+1,d+n+1);
        ans=d[1]*d[n]; sum=0;
        for (ll i=2;i*i<=ans;i++)
        {
            if (ans%i) continue;
            sum++;
            if (ans/i!=i) sum++;
        }
        for (int i=1;i<=n;i++)
        {
            if ((ans%d[i]))
            {
                ans=-1;
                break;
            }
        }
        if (n!=sum)
            ans=-1;
        cout << ans << endl;
    }
    return 0;
}
