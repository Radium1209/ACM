// 这题要交C++，G++会WA
#include <cstdio>
#include <iostream>
using namespace std;

int n,s;
double dp[1005][1005];

int main() {
    cin >> n >> s;
    dp[n][s]=0;
    for (int i=n;i>=0;i--) {
        for (int j=s;j>=0;j--) {
            if (i!=n || j!=s) {
                dp[i][j]=1.0*((n-i)*j*dp[i+1][j]+i*(s-j)*dp[i][j+1]+(n-i)*(s-j)*dp[i+1][j+1]+s*n)/(n*s-i*j);
            }
        }
    }
    printf("%.4lf\n",dp[0][0]);
    return 0;
}
