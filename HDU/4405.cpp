#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int N,M,x,y;
int go[100005];
double dp[100005];

int main()
{
    while(cin >> N >> M && M+N)
    {
        memset(go,0,sizeof(go));
        memset(dp,0,sizeof(dp));
        for (int i=1;i<=M;i++)
        {
            scanf("%d%d",&x,&y);
            go[x]=y;
        }
        for (int i=N-1;i>=0;i--)
        {
            if (!go[i])
            {
                for (int j=1;j<=6;j++)
                    dp[i]+=dp[i+j]/6.0;
                dp[i]++;
            }
            else
                dp[i]=dp[go[i]];
        }
        printf("%.4lf\n",dp[0]);
    }
    return 0;
}
