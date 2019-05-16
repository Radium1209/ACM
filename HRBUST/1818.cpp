#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
const int inf=0x3f3f3f3f;
using namespace std;

int n,sum[105],x;
int dp1[105][105],dp2[105][105];

int main()
{
    while(cin >> n)
    {
        memset(dp1,inf,sizeof(dp1));
        memset(dp2,0,sizeof(dp2));
        sum[0]=0;
        for (int i=1;i<=n;i++)
        {
            dp1[i][i]=0;
            scanf("%d",&x);
            sum[i]=sum[i-1]+x;
        }
        for (int len=1;len<n;len++)
        {
            for (int i=1;i+len<=n;i++)
            {
                int j=i+len;
                for (int k=i;k<j;k++)
                {
                    dp1[i][j]=min(dp1[i][j],dp1[i][k]+dp1[k+1][j]+sum[j]-sum[i-1]);
                    dp2[i][j]=max(dp2[i][j],dp2[i][k]+dp2[k+1][j]+sum[j]-sum[i-1]);
                }
            }
        }
        printf("%d %d\n",dp1[1][n],dp2[1][n]);
    }
    return 0;
}
