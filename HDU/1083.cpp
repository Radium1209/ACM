#include <cstdio>
#include <iostream>
#include <cstring>
const int MAXN=505;
const int MAXM=30005;
using namespace std;

struct Edge {
    int to,next;
}edge[MAXM];

int P,N,x,y;
int head[MAXN],tot;

void init()
{
    tot=0;
    memset(head,-1,sizeof(head));
}

void addedge(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}

int linker[MAXN];
bool used[MAXN];
int uN;

bool dfs(int u)
{
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        if(!used[v])
        {
            used[v]=true;
            if(linker[v]==-1 || dfs(linker[v]))
            {
                linker[v]=u;
                return true;
            }
        }
    }
    return false;
}

int hungary()
{
    int res=0;
    memset(linker,-1,sizeof(linker));
    for(int u=0;u<uN;u++)
    {
        memset(used,false,sizeof(used));
        if(dfs(u)) res++;
    }
    return res;
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        init();
        scanf("%d%d",&P,&N);
        for (int i=0;i<P;i++)
        {
            scanf("%d",&x);
            for (int j=0;j<x;j++)
            {
                scanf("%d",&y);
                addedge(i,y);
            }
        }
        uN=P;
        if (hungary()==P)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
