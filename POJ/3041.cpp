#include <cstdio>
#include <iostream>
#include <cstring>
const int MAXN=505;
const int MAXM=10005;
using namespace std;

struct Edge{
    int to,next;
}edge[MAXM];
int head[MAXN],tot;
int N,K,r,c;

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
    for (int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        if (!used[v])
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
    for (int u=1;u<=uN;u++)
    {
        memset(used,false,sizeof(used));
        if(dfs(u)) res++;
    }
    return res;
}

int main()
{
    cin >> N >> K;
    init();
    for (int i=0;i<K;i++)
    {
        scanf("%d%d",&r,&c);
        addedge(r,c);
    }
    uN=N;
    cout << hungary() << endl;
    return 0;
}
