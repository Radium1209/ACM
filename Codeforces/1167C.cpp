#include <cstdio>
#include <iostream>
#include <cstring>
typedef long long ll;
using namespace std;

int n,m,t,x,y;
int fa[500005];
ll sum[500005];

void init()
{
    for (int i=1;i<=n;i++)
    {
        fa[i]=i;
        sum[i]=1;
    }
}

int find(int x)
{
    if (x!=fa[x])
    {
        int t=fa[x];
        fa[x]=find(fa[x]);
        sum[x]=sum[fa[x]];
    }
    return fa[x];
}

void combine(int p,int q)
{
    int rp=find(p),rq=find(q);
    if (rp==rq)
        return;
    fa[rq]=rp;
    sum[rp]=sum[rq]+sum[rp];
}

int main()
{
    cin >> n >> m;
    init();
    for (int i=1;i<=m;i++)
    {
        scanf("%d",&t);
        if (t) scanf("%d",&x);
        for (int j=2;j<=t;j++)
        {
            scanf("%d",&y);
            combine(x,y);
        }
    }
    for (int i=1;i<=n;i++)
    {
        fa[i]=find(fa[i]);
        cout << sum[fa[i]] << " ";
    }
    return 0;
}
