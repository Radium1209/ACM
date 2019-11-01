#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#define MAXN 200005
using namespace std;

struct Edge {
    int to,next;
}edge[MAXN*2];
int head[MAXN],tot;
void init() {
    memset(head,-1,sizeof(head));
    tot=0;
}
void addedge(int u,int v) {
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}

int level[MAXN];
bool vis[MAXN];
int fa[MAXN];

struct node {
    int u,level;
}st,Now,Next;

void bfs() {
    int pos=1;
    memset(vis,false,sizeof(vis));
    st.u=1; st.level=1; fa[1]=1;
    vis[st.u]=true;
    queue<node> Q;
    Q.push(st);
    while(!Q.empty()) {
        Now=Q.front(); Q.pop();
        level[Now.u]=Now.level;
        for (int i=head[Now.u];i!=-1;i=edge[i].next) {
            int v=edge[i].to;
            if (!vis[v]) {
                fa[v]=Now.u;
                vis[v]=true;
                Next.u=v; Next.level=Now.level+1;
                Q.push(Next);
            }
        }
    }
}

int a[MAXN],u,v;
int b[MAXN];

int main() {
    int n;
    init();
    scanf("%d",&n);
    for (int i=1;i<=n-1;i++) {
        scanf("%d%d",&u,&v);
        addedge(u,v);
        addedge(v,u);
    }
    for (int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
    }
    bfs();
    b[0]=0;
    for (int i=1;i<=n;i++) {
        b[i]=level[a[i]];
        if (b[i]<b[i-1]) {
            printf("No\n");
            return 0;
        }
    }
    bool flag=true;
    int pos=1;
    for (int i=2;i<=n;i++) {
        if (fa[a[i]]==a[pos]) continue;
        else {
            while(fa[a[i]]!=a[pos] && pos<=n) pos++;
            if (pos>n) {
                flag=false;
                break;
            }
        }
    }
    if (flag) printf("Yes\n");
    else printf("No\n");
    return 0;
}
