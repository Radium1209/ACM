#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define MAXN 2005
typedef long long ll;
using namespace std;

struct node {
    int x,nx,y,ny;
    ll w;
}a[MAXN];

ll sum[MAXN<<2],msum[MAXN<<2],lsum[MAXN<<2],rsum[MAXN<<2];

void pushup(int rt) {
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
    msum[rt]=max(msum[rt<<1],msum[rt<<1|1]);
    msum[rt]=max(msum[rt],rsum[rt<<1]+lsum[rt<<1|1]);
    lsum[rt]=max(lsum[rt<<1],sum[rt<<1]+lsum[rt<<1|1]);
    rsum[rt]=max(rsum[rt<<1|1],sum[rt<<1|1]+rsum[rt<<1]);
}

void build(int l,int r,int rt) {
    sum[rt]=msum[rt]=lsum[rt]=rsum[rt]=0;
    if (l==r) {
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
}

void update(int p,ll c,int l,int r,int rt) {
    if (l==r) {
        lsum[rt]=rsum[rt]=msum[rt]=sum[rt]=sum[rt]+c;
        return;
    }
    int m=(l+r)>>1;
    if (p<=m) update(p,c,lson);
    if (p>m) update(p,c,rson);
    pushup(rt);
}

bool cmpx(node a1,node a2) {
    if (a1.x==a2.x)
        return a1.y<a2.y;
    return a1.x<a2.x;
}

bool cmpy(node a1,node a2) {
    if (a1.y==a2.y)
        return a1.x<a2.x;
    return a1.y<a2.y;
}

int T,n,sx,sy;

int main() {
    scanf("%d",&T);
    while(T--) {
        sx=sy=0;
        scanf("%d",&n);
        for (int i=1;i<=n;i++) {
            scanf("%d%d%lld",&a[i].x,&a[i].y,&a[i].w);
        }
        sort(a+1,a+1+n,cmpx);
        for (int i=1;i<=n;i++) {
            if (i==1 || (a[i].x!=a[i-1].x)) {
                a[i].nx=++sx;
            } else {
                a[i].nx=a[i-1].nx;
            }
        }
        sort(a+1,a+1+n,cmpy);
        for (int i=1;i<=n;i++) {
            if (i==1 || (a[i].y!=a[i-1].y)) {
                a[i].ny=++sy;
            } else {
                a[i].ny=a[i-1].ny;
            }
        }
        ll ans=0;
        for (int i=1;i<=sy;i++) {
            build(1,n,1);
            for (int j=1;j<=n;j++) {
                if (a[j].ny>=i) {
                    update(a[j].nx,a[j].w,1,n,1);
                }
                if (j==n || a[j+1].ny!=a[j].ny) {
                    ans=max(ans,msum[1]);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
