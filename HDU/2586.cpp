#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#define MAXN 40005
using namespace std;

struct Edge {
    int w,e,next;
}edge[MAXN<<1];

struct Node {
    int fa,dep,w;
    vector<int> son;
}tree[MAXN];

int t,n,m,cnt,a,b,c,L,R,ans;
int head[MAXN],vis[MAXN];

void addedge(int u,int v,int w) {
    edge[cnt].w=w;
    edge[cnt].e=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}

void dfs(int father,int depth) {
    for (int i=head[father];i!=-1;i=edge[i].next) {
        int Next=edge[i].e;
        if (!vis[Next]) {
            tree[father].son.push_back(Next);
            tree[Next].dep=depth;
            tree[Next].fa=father;
            tree[Next].w=edge[i].w;
            vis[Next]=1;
            dfs(Next,depth+1);
        }
    }
}

int main() {
    cin >> t;
    while(t--) {
        scanf("%d%d",&n,&m);
        memset(head,-1,sizeof(head));
        memset(vis,0,sizeof(vis));
        cnt=1; ans=0;
        for (int i=1;i<=n-1;i++) {
            scanf("%d%d%d",&a,&b,&c);
            addedge(a,b,c);
            addedge(b,a,c);
        }
        tree[1].fa=1; vis[1]=1; tree[1].dep=0;
        dfs(1,1);
        for (int i=1;i<=m;i++) {
            scanf("%d%d",&L,&R);
        ans=0;
            while(L!=R) {
                if (tree[L].dep>tree[R].dep) {
                    ans+=tree[L].w;
                    L=tree[L].fa;
                } else {
                    ans+=tree[R].w;
                    R=tree[R].fa;
                }
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
