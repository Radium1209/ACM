#include <cstdio>
#include <iostream>
#include <algorithm>
typedef long long ll;
const int MAXN=100005;
using namespace std;

ll n;
ll h1[MAXN],h2[MAXN];
ll a[MAXN],b[MAXN],c[MAXN];

int main() {
    cin >> n;
    a[0]=b[0]=c[0]=0;
    for (int i=1;i<=n;i++) {
        scanf("%I64d",&h1[i]);
    }
    for (int i=1;i<=n;i++) {
        scanf("%I64d",&h2[i]);
    }
    for (int i=1;i<=n;i++) {
        a[i]=max(b[i-1]+h1[i],c[i-1]+h1[i]);
        b[i]=max(a[i-1]+h2[i],c[i-1]+h2[i]);
        c[i]=max(a[i-1],b[i-1]);
    }
    cout << max(a[n],max(b[n],c[n])) << endl;
    return 0;
}
