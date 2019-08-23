#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
typedef long long ll;
using namespace std;

int T,n;
priority_queue<ll,vector<ll>,greater<ll> > Q;
map<ll,int> M;
ll ans,a,cnt;

int main() {
    scanf("%d",&T);
    while(T--) {
        while(!Q.empty()) Q.pop();
        M.clear(); ans=cnt=0;
        scanf("%d",&n);
        for (int i=1;i<=n;i++) {
            scanf("%lld",&a);
            if (!Q.empty() && Q.top()<a) {
                ans+=(a-Q.top());
                cnt++; Q.push(a);
                if (M[Q.top()]) {
                    cnt--;
                    M[Q.top()]--;
                }
                M[a]++;
                Q.pop();
            }
            Q.push(a);
        }
        printf("%lld %lld\n",ans,cnt*2);
    }
    return 0;
}
