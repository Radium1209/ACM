#include <cstdio>
#include <iostream>
const int inf=0x3f3f3f3f;
using namespace std;

int T,Q;

int cal(int n)
{
    int t=5,ret=0;
    while(n/t)
    {
        ret+=n/t;
        t*=5;
    }
    return ret;
}

int solve()
{
    int l=1,r=inf,mid;
    while(l<r)
    {
        mid=(l+r)/2;
        if (cal(mid)>Q)
            r=mid-1;
        else
            l=mid+1;
    }
    if (cal(l)==Q)
        return l;
    else if (cal(l+1)==Q)
        return l+1;
    else if (cal(r)==Q)
        return r;
    else if (cal(r-1)==Q)
        return r-1;
    else
        return -1;
}

int main()
{
    cin >> T;
    for (int cnt=1;cnt<=T;cnt++)
    {
        scanf("%d",&Q);
        int ans=solve();
        printf("Case %d: ",cnt);
        if (ans==-1)
            printf("impossible\n");
        else
            printf("%d\n",ans/5*5);
    }
    return 0;
}
