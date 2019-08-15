#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int n,m,ans=0;
string s[105];
int a[105];

int main() {
    memset(a,0,sizeof(a));
    cin >> n >> m;
    for (int i=1;i<=n;i++) {
        cin >> s[i];
    }
    int maxn;
    for (int i=0;i<m;i++) {
        maxn=0;
        for (int j=1;j<=n;j++) {
            if (s[j][i]-'0'>maxn) {
                maxn=s[j][i]-'0';
            }
        }
        for (int j=1;j<=n;j++) {
            if (s[j][i]-'0'==maxn) {
                a[j]++;
            }
        }
    }
    for (int i=1;i<=100;i++) {
        if (a[i])
            ans++;
    }
    cout << ans << endl;
    return 0;
}
