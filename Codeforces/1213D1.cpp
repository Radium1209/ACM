#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;
priority_queue<int,vector<int>,greater<int> > Q[200005];
stack<int> s;
int n,k;
int a[200005];
int ans=1e8;

int main() {
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        while(!s.empty()) s.pop();
        while(a[i]) {
            s.push(a[i]%2);
            a[i]/=2;
        }
        int sz=s.size(),tmp=0;
        for (int i=1;i<=sz;i++) {
            tmp=tmp<<1|s.top();
            s.pop();
            Q[tmp].push(sz-i);
        }
    }
    for (int i=0;i<=200000;i++) {
        if (Q[i].size()>=k) {
            int sum=0;
            for (int j=1;j<=k;j++) {
                sum+=Q[i].top();
                Q[i].pop();
            }
            ans=min(ans,sum);
        }
    }
    cout << ans << endl;
    return 0;
}
