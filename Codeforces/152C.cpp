#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
typedef long long ll;
const ll MOD=1e9+7;
using namespace std;

int n,m;
string s[105];
int vis[30];
ll ans=1,t;

int main() {
    cin >> n >> m;
    for (int i=1;i<=n;i++) {
        cin >> s[i];
    }
    for (int i=0;i<m;i++) {
        memset(vis,0,sizeof(vis));
        for (int j=1;j<=n;j++) {
            vis[s[j][i]-'A']=1;
        }
        t=0;
        for (int i=0;i<26;i++) {
            t+=(ll)vis[i];
        }
        ans=ans*t%MOD;
    }
    cout << ans%MOD << endl;
    return 0;
}
