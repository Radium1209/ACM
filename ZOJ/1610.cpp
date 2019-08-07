#include <cstdio>
#include <iostream>
#include <cstring>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define MAXN 8005
using namespace std;

int n,x1,x2,c,maxn,maxc,cnt;
int col[MAXN<<2],sum[MAXN<<2],ans[MAXN<<2];

void pushdown(int rt) {
    if (col[rt]!=-1) {
        col[rt<<1]=col[rt<<1|1]=col[rt];
        col[rt]=-1;
    }
}

void update(int L,int R,int c,int l,int r,int rt) {
    if (L<=l && r<=R) {
        col[rt]=c;
        return;
    }
    pushdown(rt);
    int m=(l+r)>>1;
    if (L<=m) update(L,R,c,lson);
    if (m<R) update(L,R,c,rson);
}

void query(int l,int r,int rt) {
    if (l==r) {
        sum[cnt++]=col[rt];
        return;
    }
    pushdown(rt);
    int m=(l+r)>>1;
    query(lson);
    query(rson);
}

int main() {
    while(cin >> n) {
        memset(col,-1,sizeof(col));
        memset(sum,-1,sizeof(sum));
        memset(ans,0,sizeof(ans));
        maxn=-1; maxc=-1; cnt=0;
        for (int i=0;i<n;i++) {
            scanf("%d%d%d",&x1,&x2,&c);
            if (x2>maxn) maxn=x2;
            if (c>maxc) maxc=c;
            update(x1,x2-1,c,0,8000,1);
        }
        query(0,8000,1);
        for (int i=0;i<cnt;i++) {
            if (sum[i]!=-1 && (i==0 || sum[i]!=sum[i-1]))
                ans[sum[i]]++;
        }
        for (int i=0;i<=maxc;i++) {
            if (ans[i]) {
                printf("%d %d\n",i,ans[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
