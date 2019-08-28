#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
#define MAXN 1005
#define MAXM 200005
#define inf 0x3f3f3f3f
//#define inf 1e9
using namespace std;

inline const int read() {
    register int x=0,f=1;
    register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
struct Edge{
    int to,w,next;
}e1[MAXM],e2[MAXM];
bool vis[MAXN];
struct node {
    int id; // 当前结点编号
    int f; // 经过当前结点的最短路
    int g; // s->当前结点的最短路
    node (int id=0,int f=0,int g=0):id(id),f(f),g(g){}
    bool operator < (const node &a) const {
        if (f==a.f) return g>a.g;
        return f>a.f;
    }
};
int tot,n,m,k,head1[MAXN],head2[MAXN];
int dis[MAXN];
void addedge(int u,int v,int w) {
    e1[tot].to=v;
    e1[tot].w=w;
    e1[tot].next=head1[u];
    head1[u]=tot++;
    e2[tot].to=u;
    e2[tot].w=w;
    e2[tot].next=head2[v];
    head2[v]=tot++;
}
void init() {
    tot=0;
    memset(head1,-1,sizeof(head1));
    memset(head2,-1,sizeof(head2));
    memset(vis,0,sizeof(vis));
}
void spfa(int s) {
    queue<int> Q;
    memset(dis,inf,sizeof(dis));
    //for (int i=1;i<=n;i++)
    //    dis[i]=1e9;
    dis[s]=0; vis[s]=1;
    Q.push(s);
    while(!Q.empty()) {
        int Now=Q.front(); Q.pop();
        vis[Now]=0;
        for (int i=head2[Now];i!=-1;i=e2[i].next) {
            int v=e2[i].to,w=e2[i].w;
            if (dis[v]>dis[Now]+w) {
                dis[v]=dis[Now]+w;
                if (!vis[v]) {
                    vis[v]=1;
                    Q.push(v);
                }
            }
        }
    }
}
void Astar(int s,int t) {
    if (s==t) k++;
    priority_queue<node> Q;
    Q.push(node(s,0,0));
    int cnt=0;
    while(!Q.empty()) {
        node h=Q.top(); Q.pop();
        if (h.id==t) {
            if (++cnt==k) {
                printf("%d\n",h.f);
                return;
            }
        }
        for (int i=head1[h.id];i!=-1;i=e1[i].next) {
            Q.push(node(e1[i].to,h.g+e1[i].w+dis[e1[i].to],h.g+e1[i].w));
        }
    }
    puts("-1");
}

int main() {
    int u,v,w,s,t;
    init();
    n=read(); m=read();
    for (int i=1;i<=m;i++) {
        u=read(); v=read(); w=read();
        addedge(u,v,w);
    }
    s=read(); t=read(); k=read();
    spfa(t);
    Astar(s,t);
    return 0;
}
