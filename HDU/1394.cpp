#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int sum=0,n,a[5005],BIT[5005];

int lowbit(int x) {
    return x&-x;
}

void update(int p) {
    while(p<=n) {
        BIT[p]++;
        p+=lowbit(p);
    }
}

int query(int p) {
    int ret=0;
    while(p) {
        ret+=BIT[p];
        p-=lowbit(p);
    }
    return ret;
}

int main() {
    while(scanf("%d",&n)!=EOF) {
        sum=0;
        for (int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
            BIT[i]=0;
        }
        for (int i=1;i<=n;i++) {
            update(a[i]+1);
            sum+=(i-query(a[i]+1));
        }
        int ans=sum;
        for (int i=1;i<=n;i++) {
            sum=sum+(n-1-a[i])-a[i];
            ans=min(sum,ans);
        }
        cout << ans << endl;
    }
    return 0;
}
