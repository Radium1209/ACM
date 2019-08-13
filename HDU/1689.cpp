#include <cstdio>
#include <iostream>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define MAXN 100005
using namespace std;

int T,N,Q,x,y,z;
int sum[MAXN<<2],lazy[MAXN<<2];

void pushup(int rt) {
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

void pushdown(int rt,int m) {
    // 是否有lazy标记
    if (lazy[rt]) {
        lazy[rt<<1]=lazy[rt<<1|1]=lazy[rt];
        sum[rt<<1]=lazy[rt]*(m-(m>>1));
        sum[rt<<1|1]=lazy[rt]*(m>>1);
        lazy[rt]=0;
    }
}

void build(int l,int r,int rt) {
    lazy[rt]=0;
    if (l==r) {
        sum[rt]=1;
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}

void update(int L,int R,int z,int l,int r,int rt) {
    if (L<=l && r<=R) {
        // 进行lazy标记
        lazy[rt]=z;
        // 注意长度为r-l+1
        sum[rt]=z*(r-l+1);
        return;
    }
    pushdown(rt,r-l+1);
    int m=(l+r)>>1;
    if (L<=m) update(L,R,z,lson);
    if (m<R) update(L,R,z,rson);
    pushup(rt);
}

int query(int L,int R,int l,int r,int rt) {
    if (L<=l && r<=R) {
        return sum[rt];
    }
    pushdown(rt,r-l+1); //与单点更新时的唯一区别
    int m=(l+r)>>1;
    int ret=0;
    if (L<=m) ret+=query(L,R,lson);
    if (m<R) ret+=query(L,R,rson);
    return ret;

}

int main() {
    cin >> T;
    for (int cnt=1;cnt<=T;cnt++) {
        scanf("%d%d",&N,&Q);
        build(1,N,1);
        while(Q--) {
            scanf("%d%d%d",&x,&y,&z);
            update(x,y,z,1,N,1);
        }
        printf("Case %d: The total value of the hook is %d.\n",cnt,query(1,N,1,N,1));
    }
    return 0;
}
