#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define MAXN 80005
using namespace std;

struct Edge {
    int to,next;
}edge[MAXN*2];
int head[MAXN],tot,cnt;
int deep[MAXN];
int fa[MAXN];
int t[MAXN];
int w[MAXN];
void init() {
    tot=0;
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v) {
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}
void dfs(int u,int pre,int d) {
    deep[u]=d;
    fa[u]=pre;
    for (int i=head[u];i!=-1;i=edge[i].next) {
        int v=edge[i].to;
        if (v!=pre) dfs(v,u,d+1);
    }
}
int getans(int u,int v,int k) {
    cnt=0;
    while(u!=v) {
        if (deep[u]>deep[v])
            t[++cnt]=w[u],u=fa[u];
        else
            t[++cnt]=w[v],v=fa[v];
    }
    t[++cnt]=w[u];
    if (cnt<k) return -1;
    sort(t+1,t+cnt+1,greater<int>());
    return t[k];
}

int main() {
    int N,Q,u,v,k,a,b,ans;
    init();
    scanf("%d%d",&N,&Q);
    for (int i=1;i<=N;i++)
        scanf("%d",&w[i]);
    for (int i=1;i<=N-1;i++) {
        scanf("%d%d",&u,&v);
        addedge(u,v);
        addedge(v,u);
    }
    dfs(1,1,1);
    for (int i=1;i<=Q;i++) {
        scanf("%d%d%d",&k,&a,&b);
        if (k==0) w[a]=b;
        else {
            ans=getans(a,b,k);
            if (ans==-1) printf("invalid request!\n");
            else printf("%d\n",ans);
        }
    }
    return 0;
}
