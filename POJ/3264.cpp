#include <cstdio>
#include <iostream>
#include <algorithm>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define MAXN 50005
#define INF 1e9+5
using namespace std;

int N,Q,x,y;
int Max[MAXN<<2],Min[MAXN<<2];

void pushup(int rt) {
    Max[rt]=max(Max[rt<<1],Max[rt<<1|1]);
    Min[rt]=min(Min[rt<<1],Min[rt<<1|1]);
}

void build(int l,int r,int rt) {
    if (l==r) {
        scanf("%d",&Max[rt]);
        Min[rt]=Max[rt];
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}

int queryMax(int L,int R,int l,int r,int rt) {
    if (L<=l && r<=R) {
        return Max[rt];
    }
    int m=(l+r)>>1;
    int ret=0;
    if (L<=m) ret=max(ret,queryMax(L,R,lson));
    if (m<R) ret=max(ret,queryMax(L,R,rson));
    return ret;
}

int queryMin(int L,int R,int l,int r,int rt) {
    if (L<=l && r<=R) {
        return Min[rt];
    }
    int m=(l+r)>>1;
    int ret=INF;
    if (L<=m) ret=min(ret,queryMin(L,R,lson));
    if (m<R) ret=min(ret,queryMin(L,R,rson));
    return ret;
}

int main() {
    while(cin >> N >> Q) {
        build(1,N,1);
        while(Q--) {
            scanf("%d%d",&x,&y);
            printf("%d\n",queryMax(x,y,1,N,1)-queryMin(x,y,1,N,1));
        }
    }
    return 0;
}
