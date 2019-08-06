#include <cstdio>
#include <iostream>
#include <algorithm>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define MAXN 200005
using namespace std;

int N,M,a,b;
char ch;
int Max[MAXN<<2];

void pushup(int rt) {
    Max[rt]=max(Max[rt<<1],Max[rt<<1|1]);
}

void build(int l,int r,int rt) {
    if (l==r) {
        scanf("%d",&Max[rt]);
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}

void update(int p,int x,int l,int r,int rt) {
    if (l==r) {
        Max[rt]=x;
        return;
    }
    int m=(l+r)>>1;
    if (p<=m) update(p,x,lson);
    else update(p,x,rson);
    pushup(rt);
}

int query(int L,int R,int l,int r,int rt) {
    if (L<=l && r<=R) {
        return Max[rt];
    }
    int m=(l+r)>>1;
    int ret=0;
    if (L<=m) ret=max(ret,query(L,R,lson));
    if (R>m) ret=max(ret,query(L,R,rson));
    return ret;
}

int main() {
    while(~scanf("%d%d",&N,&M)) {
        build(1,N,1);
        for (int i=1;i<=M;i++) {
            getchar();
            scanf("%c %d %d",&ch,&a,&b);
            if (ch=='Q')
                printf("%d\n",query(a,b,1,N,1));
            else
                update(a,b,1,N,1);
        }
    }
    return 0;
}
