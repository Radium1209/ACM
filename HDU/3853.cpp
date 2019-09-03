// eps一定要加不然会WA或者RE
#include <cstdio>
#include <iostream>
#include <algorithm>
#define MAXN 1005
const double eps=1e-8;
using namespace std;

int R,C;
double dp[MAXN][MAXN];
double p[MAXN][MAXN][3];

int main() {
    while(scanf("%d%d",&R,&C)!=EOF) {
        for (int i=1;i<=R;i++) {
            for (int j=1;j<=C;j++) {
                for (int k=0;k<3;k++) {
                    scanf("%lf",&p[i][j][k]);
                }
            }
        }
        dp[R][C]=0;
        for (int i=R;i>=1;i--) {
            for (int j=C;j>=1;j--) {
                if (i!=R || j!=C) {
                    if (abs(1.0-p[i][j][0])>=eps)
                        dp[i][j]=(dp[i][j+1]*p[i][j][1]+dp[i+1][j]*p[i][j][2]+2.0)/(1.0-p[i][j][0]);
                }
            }
        }
        printf("%.3lf\n",dp[1][1]);
    }
}
