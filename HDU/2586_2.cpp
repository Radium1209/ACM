#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int MAXN = 40005;
const int DEG = 32;

struct Edge {
    int to,next,w;
}edge[MAXN*2];
int head[MAXN],tot;
void addedge(int u,int v,int w) {
    edge[tot].to = v;
    edge[tot].w = w;
    edge[tot].next = head[u];
    head[u] = tot++;
}

void init() {
    tot = 0;
    memset(head,-1,sizeof(head));
}
int fa[MAXN][DEG],cost[MAXN][DEG];
int deg[MAXN];

void BFS(int root) {
    queue<int>que;
    deg[root] = 0;
    fa[root][0] = root;
    que.push(root);
    while(!que.empty()) {
        int tmp = que.front();
        que.pop();
        for (int i = 1;i < DEG;i++) {
            fa[tmp][i] = fa[fa[tmp][i-1]][i-1];
            cost[tmp][i] = cost[fa[tmp][i-1]][i-1] + cost[tmp][i-1];
        }
        for (int i = head[tmp];i != -1;i = edge[i].next) {
            int v = edge[i].to;
            if (v == fa[tmp][0]) continue;
            cost[v][0] = edge[i].w;
            deg[v] = deg[tmp] + 1;
            fa[v][0] = tmp;
            que.push(v);
        }
    }
}

int LCA(int u,int v) {
    if (deg[u] > deg[v]) swap(u,v);
    int hu = deg[u], hv = deg[v];
    int tu = u, tv = v, ans = 0;
    for (int det = hv - hu,i = 0;det;det >>= 1,i++) {
        if (det&1) {
            ans += cost[tv][i];
            tv = fa[tv][i];
        }
    }
    if (tu == tv) return ans;
    for (int i = DEG-1;i>=0 && tu!=tv;i--) {
        if (fa[tu][i] == fa[tv][i])
            continue;
        ans += cost[tu][i] + cost[tv][i];
        tu = fa[tu][i];
        tv = fa[tv][i];
    }
    ans +=cost[tu][0] + cost[tv][0];
    return ans;
}

bool flag[MAXN];
int main() {
    int T,n,m,u,v,w;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&n,&m);
        init();
        memset(flag,false,sizeof(flag));
        memset(cost,0,sizeof(cost));
        memset(deg,0,sizeof(deg));
        for (int i = 1;i < n;i++) {
            scanf("%d%d%d",&u,&v,&w);
            addedge(u,v,w);
            addedge(v,u,w);
            flag[v] = true;
        }
        int root;
        for (int i = 1;i <= n;i++) {
            if (!flag[i]) {
                root = i;
                break;
            }
        }
        BFS(1);
        for (int i = 1;i <= m;i++) {
            scanf("%d%d",&u,&v);
            printf("%d\n",LCA(u,v));
        }
    }
    return 0;
}
