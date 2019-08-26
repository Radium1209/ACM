#include <cstdio>
#include <iostream>
#include <cstring>
const int MAXN = 100005;
using namespace std;
struct Edge{
    int to,next;
}edge[MAXN*2];
int head[MAXN],tot;
int top[MAXN];
int fa[MAXN];
int deep[MAXN];
int num[MAXN];
int p[MAXN];
int fp[MAXN];
int son[MAXN];
int pos;
void init() {
    tot=0;
    memset(head,-1,sizeof(head));
    pos=0;
    memset(son,-1,sizeof(son));
}
void addedge(int u,int v) {
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}
void dfs1(int u,int pre,int d) {
    deep[u]=d;
    fa[u]=pre;
    num[u]=1;
    for (int i=head[u];i!=-1;i=edge[i].next) {
        int v=edge[i].to;
        if (v!=pre) {
            dfs1(v,u,d+1);
            num[u]+=num[v];
            if (son[u]==-1 || num[v]>num[son[u]])
                son[u]=v;
        }
    }
}
void getpos(int u,int sp) {
    top[u]=sp;
    p[u]=pos++;
    fp[p[u]]=u;
    if(son[u]==-1) return;
    getpos(son[u],sp);
    for (int i=head[u];i!=-1;i=edge[i].next) {
        int v=edge[i].to;
        if (v!=son[u] && v!=fa[u])
            getpos(v,v);
    }
}
struct Node {
    int l,r;
    int sum;
}segTree[MAXN<<2];
void build(int rt,int l,int r) {
    segTree[rt].l=l;
    segTree[rt].r=r;
    segTree[rt].sum=0;
    if (l==r) return;
    int m=(l+r)/2;
    build(rt<<1,l,m);
    build(rt<<1|1,m+1,r);
}
void pushup(int rt) {
    segTree[rt].sum=segTree[rt<<1].sum+segTree[rt<<1|1].sum;
}
void update(int rt,int k,int val) {
    if (segTree[rt].l==k && segTree[rt].r==k) {
        segTree[rt].sum=val;
        return;
    }
    int m=(segTree[rt].l+segTree[rt].r)/2;
    if (k<=m) update(rt<<1,k,val);
    else update(rt<<1|1,k,val);
    pushup(rt);
}
int query(int rt,int l,int r) {
    if (l>segTree[rt].r || r<segTree[rt].l) return 0;
    if (l<=segTree[rt].l && segTree[rt].r<=r) return segTree[rt].sum;
    int m=(segTree[rt].l+segTree[rt].r)/2;
    return query(rt<<1,l,r)+query(rt<<1|1,l,r);
}
int solve(int u,int v) {
    int f1=top[u],f2=top[v];
    int ret=0;
    while(f1!=f2) {
        if (deep[f1]<deep[f2]) {
            swap(f1,f2);
            swap(u,v);
        }
        ret+=query(1,p[f1],p[u]);
        u=fa[f1]; f1=top[u];
    }
    if (u==v) return ret;
    if (deep[u]>deep[v]) swap(u,v);
    ret+=query(1,p[son[u]],p[v]);
    return ret;
}
int e[MAXN][3];

int main() {
    int n,q,s,op,a,b,c;
    while(scanf("%d%d%d",&n,&q,&s)!=EOF) {
        init();
        for (int i=0;i<n-1;i++) {
            scanf("%d%d%d",&e[i][0],&e[i][1],&e[i][2]);
            addedge(e[i][0],e[i][1]);
            addedge(e[i][1],e[i][0]);
        }
        dfs1(1,0,0);
        getpos(1,1);
        build(1,0,pos-1);
        for (int i=0;i<n-1;i++) {
            if (deep[e[i][0]] > deep[e[i][1]])
                swap(e[i][0],e[i][1]);
            update(1,p[e[i][1]],e[i][2]);
        }
        for (int i=1;i<=q;i++) {
            scanf("%d",&op);
            if (op==0) {
                scanf("%d",&c);
                printf("%d\n",solve(s,c));
                s=c;
            } else {
                scanf("%d%d",&a,&b);
                update(1,p[e[a-1][1]],b);
            }
        }
    }
    return 0;
}
