#include <cstdio>
#include <iostream>
#include <cstring>
const int MAXN=10010dd;
const int MAXM=50010;
using namespace std;
struct Edge{
    int to,next;
}edge[MAXM];
int head[MAXN],tot;
int Low[MAXN],DFN[MAXN],Stack[MAXN],Belong[MAXN];
int Index,top;
int scc,cnt=0,ans;
bool Instack[MAXN];
int num[MAXN];
int outDeg[MAXN];
void addedge(int u,int v) {
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}
void init() {
    tot=0;
    memset(head,-1,sizeof(head));
}
void Tarjan(int u) {
    int v;
    Low[u]=DFN[u]=++Index;
    Stack[top++]=u;
    Instack[u]=true;
    for (int i=head[u];i!=-1;i=edge[i].next) {
        v=edge[i].to;
        if (!DFN[v]) {
            Tarjan(v);
            if (Low[u]>Low[v]) Low[u]=Low[v];
        } else if (Instack[v] && Low[u]>DFN[v]) {
            Low[u]=DFN[v];
        }
    }
    if (Low[u]==DFN[u]) {
        scc++;
        do {
            v=Stack[--top];
            Instack[v]=false;
            Belong[v]=scc;
            num[scc]++;
        }
        while(v!=u);
    }
}
void solve(int N) {
    memset(DFN,0,sizeof(DFN));
    memset(Instack,false,sizeof(Instack));
    memset(num,0,sizeof(num));
    Index=scc=top=0;
    for (int i=1;i<=N;i++)
        if (!DFN[i])
            Tarjan(i);
}

int main() {
    int N,M,u,v;
    scanf("%d%d",&N,&M);
    init();
    for (int i=1;i<=M;i++) {
        scanf("%d%d",&u,&v);
        addedge(u,v);
    }
    solve(N); cnt=0;
    memset(outDeg,0,sizeof(outDeg));
    for (int u=1;u<=N;u++) {
        for (int i=head[u];i!=-1;i=edge[i].next) {
            int v=edge[i].to;
            if (Belong[u]!=Belong[v]) {
                outDeg[Belong[u]]++;
            }
        }
    }
    for (int i=1;i<=scc;i++) {
        if (outDeg[i]==0) {
            cnt++;
            ans=num[i];
        }
    }
    if (cnt==1) printf("%d\n",ans);
    else printf("0\n");
    return 0;
}
