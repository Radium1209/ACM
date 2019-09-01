#include <cstdio>
#include <iostream>
using namespace std;

int t,n,minn,ans;
int a[150005];

int main() {
    scanf("%d",&t);
    while(t--) {
        minn=1e6+5; ans=0;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for (int i=n;i>=1;i--) {
            minn=min(minn,a[i]);
            if (a[i]>minn) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
