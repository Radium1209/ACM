#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int ans=0,n,k,x;
int sum[1005];

int main() {
    memset(sum,0,sizeof(sum));
    cin >> n >> k;
    for (int i=0;i<n;i++) {
        scanf("%d",&x);
        sum[x]++;
    }
    n=(n+1)/2;
    for (int i=1;i<=1000;i++) {
        if (sum[i]%2==0) {
            if (2*n>=sum[i]) {
                n-=sum[i]/2;
                ans+=sum[i];
                sum[i]=0;
            } else {
                ans+=n*2;
                n=0;
                sum[i]-=2*n;
            }
        } else {
            if (2*n>=sum[i]-1) {
                n-=(sum[i]-1)/2;
                ans+=(sum[i]-1);
                sum[i]=sum[i]-sum[i]/2*2;
            } else {
                ans+=n*2;
                n=0;
                sum[i]-=2*n;
            }
        }
    }
    for (int i=1;i<=1000;i++) {
        if (sum[i] && sum[i]%2) {
            if (n*2>=sum[i]) {
                n-=(sum[i]+1)/2;
                ans+=sum[i];
            }
            else {
                ans+=n*2;
                n=0;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
