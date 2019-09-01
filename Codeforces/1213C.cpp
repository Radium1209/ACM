#include <cstdio>
#include <iostream>
typedef long long ll;
using namespace std;

int q;
ll n,m;
ll t[15],x,top,ans;

int main() {
    scanf("%d",&q);
    while(q--) {
        scanf("%I64d%I64d",&n,&m);
        x=n/m; ans=0;
        for (ll i=1;i<=10;i++) {
            if (m*i>n) t[i]=0;
            else t[i]=m*i%10;
        }
        top=x%10; x/=10; if (top==0) top=10,x--;
        for (ll i=1;i<=10;i++) {
            if (x>=0)
                ans+=t[i]*(i<=top?x+1:x);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
