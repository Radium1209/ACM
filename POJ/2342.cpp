#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int fa[6005],vis[6005],dp[6005][2],T;

void dfs(int node)
{
    vis[node]=1;
    for (int i=1;i<=T;i++)
    {
        if (!vis[i] && fa[i]==node)
        {
            dfs(i);
            dp[node][1]+=dp[i][0];
            dp[node][0]+=max(dp[i][0],dp[i][1]);
        }
    }
}

int main()
{
    cin >> T;
    for (int i=1;i<=T;i++)
        scanf("%d",&dp[i][1]);
    int root=0,l,k;
    while(scanf("%d%d",&l,&k)&&(l+k))
    {
        fa[l]=k;
        root=k;
    }
    dfs(root);
    cout << max(dp[root][1],dp[root][0]) << endl;
    return 0;
}
