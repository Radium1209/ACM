#include <cstdio>
#include <iostream>
#include <algorithm>
#define left rt<<1
#define right rt<<1|1
#define MAXN 100005
using namespace std;

int n,q,aa,bb;
int U,D,L,R;
struct node {
    int x,y;
}a[MAXN];

int cnt=0;
struct segTree {
    int le,ri;
    int u,d,l,r,pu,pd,pl,pr;
}t[MAXN<<2];

void pushup(int rt) {
    if (t[left].u>t[right].u) {
        t[rt].u=t[left].u;
        t[rt].pu=t[left].pu;
    } else {
        t[rt].u=t[right].u;
        t[rt].pu=t[right].pu;
    }
    if (t[left].r>t[right].r) {
        t[rt].r=t[left].r;
        t[rt].pr=t[left].pr;
    } else {
        t[rt].r=t[right].r;
        t[rt].pr=t[right].pr;
    }
    if (t[left].d<t[right].d) {
        t[rt].d=t[left].d;
        t[rt].pd=t[left].pd;
    } else {
        t[rt].d=t[right].d;
        t[rt].pd=t[right].pd;
    }
    if (t[left].l<t[right].l) {
        t[rt].l=t[left].l;
        t[rt].pl=t[left].pl;
    } else {
        t[rt].l=t[right].l;
        t[rt].pl=t[right].pl;
    }
}

void build(int rt,int l,int r) {
    t[rt].le=l; t[rt].ri=r;
    t[rt].u=t[rt].r=-2e9; t[rt].d=t[rt].l=2e9;
    if (l==r) {
        t[rt].u=t[rt].d=a[l].y;
        t[rt].l=t[rt].r=a[l].x;
        t[rt].pu=t[rt].pd=t[rt].pl=t[rt].pr=++cnt;
        return;
    }
    int m=(l+r)>>1;
    build(left,l,m);
    build(right,m+1,r);
    pushup(rt);
}

int query_up(int rt,int L,int R) {
    if (L<=t[rt].le && t[rt].ri<=R)
        return t[rt].u;
    int m=(t[rt].le+t[rt].ri)>>1;
    int ret=-2e9;
    if (L<=m) ret=max(ret,query_up(left,L,R));
    if (R>m) ret=max(ret,query_up(right,L,R));
    return ret;
}

int query_down(int rt,int L,int R) {
    if (L<=t[rt].le && t[rt].ri<=R)
        return t[rt].d;
    int m=(t[rt].le+t[rt].ri)>>1;
    int ret=2e9;
    if (L<=m) ret=min(ret,query_down(left,L,R));
    if (R>m) ret=min(ret,query_down(right,L,R));
    return ret;
}

int query_right(int rt,int L,int R) {
    if (L<=t[rt].le && t[rt].ri<=R)
        return t[rt].r;
    int m=(t[rt].le+t[rt].ri)>>1;
    int ret=-2e9;
    if (L<=m) ret=max(ret,query_right(left,L,R));
    if (R>m) ret=max(ret,query_right(right,L,R));
    return ret;
}

int query_left(int rt,int L,int R) {
    if (L<=t[rt].le && t[rt].ri<=R)
        return t[rt].l;
    int m=(t[rt].le+t[rt].ri)>>1;
    int ret=2e9;
    if (L<=m) ret=min(ret,query_left(left,L,R));
    if (R>m) ret=min(ret,query_left(right,L,R));
    return ret;
}

int query_pu(int rt,int L,int R) {
    if (L<=t[rt].le && t[rt].ri<=R)
        return t[rt].pu;
    int m=(t[rt].le+t[rt].ri)>>1;
    int ret=-2e9,ans=0,tmp;
    if (L<=m) {
        tmp=query_pu(left,L,R);
        if (a[tmp].y>ret) {
            ret=a[tmp].y;
            ans=tmp;
        }
    }
    if (R>m) {
        tmp=query_pu(right,L,R);
        if (a[tmp].y>ret) {
            ret=a[tmp].y;
            ans=tmp;
        }
    }
    return ans;
}

int query_pd(int rt,int L,int R) {
    if (L<=t[rt].le && t[rt].ri<=R)
        return t[rt].pd;
    int m=(t[rt].le+t[rt].ri)>>1;
    int ret=2e9,ans=0,tmp;
    if (L<=m) {
        tmp=query_pd(left,L,R);
        if (a[tmp].y<ret) {
            ret=a[tmp].y;
            ans=tmp;
        }
    }
    if (R>m) {
        tmp=query_pd(right,L,R);
        if (a[tmp].y<ret) {
            ret=a[tmp].y;
            ans=tmp;
        }
    }
    return ans;
}

int query_pr(int rt,int L,int R) {
    if (L<=t[rt].le && t[rt].ri<=R)
        return t[rt].pr;
    int m=(t[rt].le+t[rt].ri)>>1;
    int ret=-2e9,ans=0,tmp;
    if (L<=m) {
        tmp=query_pr(left,L,R);
        if (a[tmp].x>ret) {
            ret=a[tmp].x;
            ans=tmp;
        }
    }
    if (R>m) {
        tmp=query_pr(right,L,R);
        if (a[tmp].x>ret) {
            ret=a[tmp].x;
            ans=tmp;
        }
    }
    return ans;
}

int query_pl(int rt,int L,int R) {
    if (L<=t[rt].le && t[rt].ri<=R)
        return t[rt].pl;
    int m=(t[rt].le+t[rt].ri)>>1;
    int ret=2e9,ans=0,tmp;
    if (L<=m) {
        tmp=query_pl(left,L,R);
        if (a[tmp].x<ret) {
            ret=a[tmp].x;
            ans=tmp;
        }
    }
    if (R>m) {
        tmp=query_pl(right,L,R);
        if (a[tmp].x<ret) {
            ret=a[tmp].x;
            ans=tmp;
        }
    }
    return ans;
}

void cal(int p) {
    U=R=-2e9; L=D=2e9;
    if (p-1>=aa) {
        U=query_up(1,aa,p-1);
        D=query_down(1,aa,p-1);
        L=query_left(1,aa,p-1);
        R=query_right(1,aa,p-1);
    }
    if (p+1<=bb) {
        U=max(U,query_up(1,p+1,bb));
        D=min(D,query_down(1,p+1,bb));
        L=min(L,query_left(1,p+1,bb));
        R=max(R,query_right(1,p+1,bb));
    }
}

int main() {
    scanf("%d%d",&n,&q);
    for (int i=1;i<=n;i++) {
        scanf("%d%d",&a[i].x,&a[i].y);
    }
    build(1,1,n);
    for (int i=1;i<=q;i++) {
        scanf("%d%d",&aa,&bb);
        int PU,PD,PL,PR,ANS=0;
        PU=query_pu(1,aa,bb); cal(PU); ANS=max(U-D,R-L);
        PD=query_pd(1,aa,bb); cal(PD); ANS=min(ANS,max(U-D,R-L));
        PL=query_pl(1,aa,bb); cal(PL); ANS=min(ANS,max(U-D,R-L));
        PR=query_pr(1,aa,bb); cal(PR); ANS=min(ANS,max(U-D,R-L));
        printf("%d\n",ANS);
    }
    return 0;
}
