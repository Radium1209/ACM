#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int n,BIT[32005],x,y;
int ans[32005];

int lowbit(int x) {
    return x&-x;
}

void update(int p) {
    while(p<=32000) {
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
    while(cin >> n) {
        memset(BIT,0,sizeof(BIT));
        memset(ans,0,sizeof(ans));
        for (int i=1;i<=n;i++) {
            scanf("%d%d",&x,&y);
            x++;
            ans[query(x)]++;
            update(x);
        }
        for (int i=0;i<n;i++) {
            printf("%d\n",ans[i]);
        }
    }
    return 0;
}
