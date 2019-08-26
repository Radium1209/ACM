#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int T,n,cnt=0;
struct node {
    char name[25];
    int x,y,z,v;
}a[105];

bool cmp(node a1,node a2) {
    return a1.v<a2.v;
}

int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n); getchar();
        for (int i=1;i<=n;i++) {
            scanf("%s%d%d%d",a[i].name,&a[i].x,&a[i].y,&a[i].z);
            getchar();
            a[i].v=a[i].x*a[i].y*a[i].z;
        }
        sort(a+1,a+1+n,cmp);
        printf("Case %d: ",++cnt);
        if (a[n].v>a[1].v) {
            printf("%s took chocolate from %s\n",a[n].name,a[1].name);
        } else {
            printf("no thief\n");
        }
    }
    return 0;
}
