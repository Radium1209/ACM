#include <cstdio>
#include <iostream>
#include <algorithm>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define left rt<<1
#define right rt<<1|1
#define MAXN 100010
using namespace std;

int T,n,m,x,a,b;
char op[5];

struct segmentTree {
    int l,r,len;
    int lv,rv;
    int ls,rs,ms;
} tree[MAXN<<2];

void pushup(int rt) {
    tree[rt].lv=tree[left].lv;
    tree[rt].rv=tree[right].rv;
    tree[rt].ls=tree[left].ls;
    tree[rt].rs=tree[right].rs;
    tree[rt].ms=max(tree[left].ms,tree[right].ms);
    if (tree[left].rv < tree[right].lv) {
        if (tree[left].ls == tree[left].len) {
            tree[rt].ls+=tree[right].ls;
        }
        if (tree[right].rs == tree[right].len) {
            tree[rt].rs+=tree[left].rs;
        }
        tree[rt].ms=max(tree[rt].ms,tree[left].rs+tree[right].ls);
    }
}

void build(int l,int r,int rt) {
    tree[rt].l=l; tree[rt].r=r; tree[rt].len=r-l+1;
    if (l==r) {
        scanf("%d",&x);
        getchar();
        tree[rt].lv=tree[rt].rv=x;
        tree[rt].ls=tree[rt].rs=tree[rt].ms=1;
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}

void update(int p,int v,int rt) {
    if (tree[rt].l == tree[rt].r) {
        tree[rt].lv=tree[rt].rv=v;
        return;
    }
    int m=(tree[rt].l+tree[rt].r)>>1;
    if (p<=m) update(p,v,left);
    else update(p,v,right);
    pushup(rt);
}

int query(int L,int R,int rt) {
    if (L<=tree[rt].l && tree[rt].r<=R) {
        return tree[rt].ms;
    }
    int ret=0;
    int m=(tree[rt].l+tree[rt].r)>>1;
    if (L<=m) ret=max(ret,query(L,R,left));
    if (m<R) ret=max(ret,query(L,R,right));
    if (tree[left].rv < tree[right].lv) {
        ret=max(ret,min(m-L+1,tree[left].rs)+min(R-m,tree[right].ls));
    }
    return ret;
}

int main() {
    cin >> T;
    while(T--) {
        scanf("%d%d",&n,&m); getchar();
        build(1,n,1);
        while(m--) {
            scanf("%s%d%d",op,&a,&b); getchar();
            if (op[0]=='Q') {
                printf("%d\n",query(a+1,b+1,1));
            } else {
                update(a+1,b,1);
            }
        }
    }
    return 0;
}
