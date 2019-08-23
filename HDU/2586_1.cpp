#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#define MAXN 40005
using namespace std;
vector<int> v[MAXN];
vector<int> w[MAXN];

int fa[MAXN][31],cost[MAXN][31],dep[MAXN];
int t,n,m,a,b,c,L,R;

void dfs(int rt,int fno) {
    fa[rt][0]=fno;
    dep[rt]=dep[fa[rt][0]]+1;
    for (int i=1;i<31;i++) {
        fa[rt][i]=fa[fa[rt][i-1]][i-1];
        cost[rt][i]=cost[fa[rt][i-1]][i-1]+cost[rt][i-1];
    }
    int sz=v[rt].size();
    for (int i=0;i<sz;i++) {
        if (v[rt][i]==fno) continue;
        cost[v[rt][i]][0]=w[rt][i];
        dfs(v[rt][i],rt);
    }
}

int lca(int x,int y) {
    if (dep[x]>dep[y]) swap(x,y);
    int tmp=dep[y]-dep[x],ans=0;
    for (int j=0;tmp;j++,tmp>>=1)
        if (tmp&1)
            ans+=cost[y][j],y=fa[y][j];
    if (y==x) return ans;
    for (int j=30;j>=0&&y!=x;j--) {
        if (fa[x][j]!=fa[y][j]) {
            ans+=cost[x][j]+cost[y][j];
            x=fa[x][j];
            y=fa[y][j];
        }
    }
    ans+=cost[x][0]+cost[y][0];
    return ans;
}

int main() {
    scanf("%d",&t);
    while(t--) {
        memset(fa,0,sizeof(fa));
        memset(cost,0,sizeof(cost));
        memset(dep,0,sizeof(dep));
        scanf("%d%d",&n,&m);
        for (int i=1;i<n;i++) {
            scanf("%d%d%d",&a,&b,&c);
            v[a].push_back(b);
            v[b].push_back(a);
            w[a].push_back(c);
            w[b].push_back(c);
        }
        dfs(1,0);
        for (int i=0;i<m;i++) {
            scanf("%d%d",&L,&R);
            printf("%d\n",lca(L,R));
        }
    }
    return 0;
}
