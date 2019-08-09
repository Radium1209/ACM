#include <cstdio>
#include <iostream>
#include <cstring>
typedef long long ll;
const int MAXN=1e5+5;
using namespace std;

int T,a[MAXN],n;
ll ans,c[MAXN],aa[MAXN],bb[MAXN],cc[MAXN],dd[MAXN];

int lowbit(int x) {
    return x&(-x);
}

int sum(int x) {
    int ret=0;
    while(x>0)
        ret+=c[x],x-=lowbit(x);
    return ret;
}

void update(int x,int d) {
    while(x<=MAXN)
        c[x]+=d,x+=lowbit(x);
}

int main()
{
    cin >> T;
    while(T--)
    {
        ans=0;
        memset(c,0,sizeof(c));
        cin >> n;
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            update(a[i],1);
            aa[i]=sum(a[i]-1);
            bb[i]=i-1-aa[i];
        }
        memset(c,0,sizeof(c));
        for (int i=n;i>=1;i--)
        {
            update(a[i],1);
            cc[i]=sum(a[i]-1);
            dd[i]=n-i-cc[i];
        }
        for (int i=1;i<=n;i++)
            ans+=aa[i]*dd[i]+bb[i]*cc[i];
        cout << ans << endl;
    }
    return 0;
}
