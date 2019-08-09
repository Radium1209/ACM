#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#define MAXN 50005
using namespace std;

int BIT[MAXN];
int T,n,x,y;
string s;

int lowbit(int x) {
    return x&-x;
}

void update(int p,int x) {
    while(p<=n) {
        BIT[p]+=x;
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
    cin >> T;
    for (int cnt=1;cnt<=T;cnt++) {
        printf("Case %d:\n",cnt);
        memset(BIT,0,sizeof(BIT));
        scanf("%d",&n);
        for (int i=1;i<=n;i++) {
            scanf("%d",&x);
            update(i,x);
        }
        while (cin>>s && s!="End") {
            if (s=="Query") {
                scanf("%d%d",&x,&y);
                printf("%d\n",query(y)-query(x-1));
            } else if (s=="Add") {
                scanf("%d%d",&x,&y);
                update(x,y);
            } else {
                scanf("%d%d",&x,&y);
                update(x,-y);
            }
        }
    }
    return 0;
}
