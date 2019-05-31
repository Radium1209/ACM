#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
typedef long long ll;
using namespace std;

string s;
ll n,l=-1,r,cnt=0;
ll ans=0;
ll L[300005],R[300005];
int flag[300005];

int main()
{
    cin >> s;
    n=s.length(); r=n;
    for (ll i=0;i<n;i++)
    {
        for (ll k=1;k<=4;k++)
        {
            if(i+2*k<n && s[i]==s[i+k] && s[i+k]==s[i+2LL*k])
            {
                if (!cnt || R[cnt]<i+2LL*k)
                    cnt++;
                L[cnt]=i;
                R[cnt]=i+2LL*k;
                break;
            }
        }
    }
    ans=0; r=R[cnt];
    for (ll i=cnt;i>=1;i--)
    {
        if (R[i]<=r)
        {
            r=R[i];
            flag[i]=1;
        }
        else
            flag[i]=0;
    }
    for (ll i=1;i<=cnt;i++)
    {
        if (!flag[i])
            continue;
        ans=ans+(L[i]-l)*(n-R[i]);
        l=L[i];
    }
    cout << ans << endl;
    return 0;
}
