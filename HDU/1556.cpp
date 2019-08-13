#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int N,a,b,t=0;
int s[100005];

int main() {
    while(cin >> N && N) {
        memset(s,0,sizeof(s));
        for (int i=1;i<=N;i++) {
            scanf("%d%d",&a,&b);
            s[a]++; s[b+1]--;
        }
        t=0;
        for (int i=1;i<=N;i++) {
            t+=s[i];
            if (i!=1) printf(" ");
            printf("%d",t);
        }
        printf("\n");
    }
    return 0;
}
