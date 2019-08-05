#include <cstdio>
#include <iostream>
#include <string>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define MAXN 50005
using namespace std;

int T,N,i,j;
int sum[MAXN<<2];
string s;

void pushup(int rt) {
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

void build(int l,int r,int rt) {
    if (l==r) {
        scanf("%d",&sum[rt]);
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}

void update(int p,int add,int l,int r,int rt) {
    if (l==r) {
        sum[rt]+=add;
        return;
    }
    int m=(l+r)>>1;
    if (p<=m) update(p,add,lson);
    else update(p,add,rson);
    pushup(rt);
}

int query(int L,int R,int l,int r,int rt) {
    if (L<=l && r<=R) {
        return sum[rt];
    }
    int m=(l+r)>>1;
    int ret=0;
    if (L<=m) ret+=query(L,R,lson);
    if (R>m) ret+=query(L,R,rson);
    return ret;
}

int main(){
    scanf("%d",&T);
    for (int cnt=1;cnt<=T;cnt++) {
        scanf("%d",&N);
        build(1,N,1);
        printf("Case %d:\n",cnt);
        while(cin >> s) {
            if (s[0]=='A') {
                scanf("%d%d",&i,&j);
                update(i,j,1,N,1);
            } else if (s[0]=='S') {
                scanf("%d%d",&i,&j);
                update(i,-j,1,N,1);
            } else if (s[0]=='Q') {
                scanf("%d%d",&i,&j);
                printf("%d\n",query(i,j,1,N,1));
            } else {
                break;
            }
        }
    }
    return 0;
}
