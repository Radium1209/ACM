#include <cstdio>
#include <iostream>
#include <algorithm>
#include <stack>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define left rt<<1
#define right rt<<1|1
#define MAXN 50005
using namespace std;

int n,m,x;
char op;
stack<int> S;

struct segmentTree {
    int l,r,len;
    int ls,rs,ms;
}tree[MAXN<<2];

void pushup(int rt) {
    tree[rt].ls=tree[left].ls;
    tree[rt].rs=tree[right].rs;
    if (tree[left].ls==tree[left].len) {
        tree[rt].ls+=tree[right].ls;
    }
    if (tree[right].rs==tree[right].len) {
        tree[rt].rs+=tree[left].rs;
    }
    tree[rt].ms=max(tree[rt].ls,tree[rt].rs);
    tree[rt].ms=max(tree[rt].ms,tree[left].rs+tree[right].ls);
}

void build(int l,int r,int rt) {
    tree[rt].l=l; tree[rt].r=r; tree[rt].len=r-l+1;
    tree[rt].ls=tree[rt].rs=tree[rt].ms=1;
    if (l==r) {
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}

void update(int p,int c,int rt) {
    if (tree[rt].l==tree[rt].r) {
        tree[rt].ls=tree[rt].rs=tree[rt].ms=c;
        return;
    }
    int m=(tree[rt].l+tree[rt].r)>>1;
    if (p<=m) update(p,c,left);
    else update(p,c,right);
    pushup(rt);
}

int query(int rt,int p) {
    if (tree[rt].l==tree[rt].r) {
        return tree[rt].ms;
    }
    int ret=0;
    int m=(tree[rt].l+tree[rt].r)>>1;
    if (p<=m) {
        if (p>=tree[left].r-tree[left].rs+1) {
            return ret=tree[left].rs+tree[right].ls;
        } else {
            return query(left,p);
        }
    } else {
        if (tree[right].ls+tree[right].l-1>=p) {
            return ret=tree[right].ls+tree[left].rs;
        } else {
            return query(right,p);
        }
    }
}

int main() {
    while(~scanf("%d%d",&n,&m)) {
        getchar();
        build(1,n,1);
        while(m--) {
            scanf("%c",&op); getchar();
            if (op=='D') {
                scanf("%d",&x); getchar();
                S.push(x);
                update(x,0,1);
            } else if (op=='Q') {
                scanf("%d",&x); getchar();
                printf("%d\n",query(1,x));
            } else if (!S.empty()) {
                update(S.top(),1,1);
                S.pop();
            }
        }
    }
    return 0;
}
