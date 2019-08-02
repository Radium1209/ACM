#include <cstdio>
#include <iostream>
#include <cstring>
typedef unsigned long long ll;
const int MAXN=100005;
const int MOD=998244353;
using namespace std;

int n;
ll t[25],a[MAXN],flag[MAXN],ans=0;
ll len[MAXN];

int get_len(ll x) {
    int len=0;
    if (x==0)
        return 1;
    while(x) {
        len++;
        x/=10;
    }
    return len;
}

int main() {
    memset(flag,0,sizeof(flag));
    t[0]=1;
    for (int i=1;i<=19;i++) {
        t[i]=t[i-1]*10;
    }
    cin >> n;
    for (int i=1;i<=n;i++) {
        cin >> a[i];
        len[i]=get_len(a[i]);
        flag[len[i]]++;
    }
    for (int i=1;i<=n;i++) {
        ll t1=a[i],t2,t3=a[i],t4;
        for (int j=1;j<=10;j++) {
            if (j<=len[i]-1) {
                t2=t1%t[2*j-1];
                t1=t1/t[2*j-1]*t[2*j]+t2;
            }
            ans=(ans+(t1%MOD*flag[j])%MOD)%MOD;
            if (j<=len[i]) {
                t4=t3%t[2*j-2];
                t3=t3/t[2*j-2]*t[2*j-1]+t4;
            }
            ans=(ans+(t3%MOD*flag[j])%MOD)%MOD;
        }
    }
    cout << ans%MOD << endl;
    return 0;
}
