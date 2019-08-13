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
    // l==r时表示的区间为[l,r],也就是单点
    if (l==r) {
        scanf("%d",&sum[rt]);
        return;
    }
    int m=(l+r)>>1;
    build(lson); // lson l,m,rt<<1
    build(rson); // rson m+1,r,rt<<1|1
    pushup(rt); // 勿忘
}

void update(int p,int add,int l,int r,int rt) {
    // 同建树，此时为单点
    if (l==r) {
        sum[rt]+=add;
        return;
    }
    int m=(l+r)>>1;
    // 若p这个结点在左子树中，更新左子树
    if (p<=m) update(p,add,lson);
    // 否则更新右子树
    else update(p,add,rson);
    // 依然需要pushup
    pushup(rt);
}

// 查询区间[L,R]
int query(int L,int R,int l,int r,int rt) {
    // 当前结点的区间[l,r]包含在[L,R]之内
    if (L<=l && r<=R) {
        return sum[rt];
    }
    int m=(l+r)>>1;
    int ret=0;
    // 注意与更新的区别
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
