#include <cstdio>
#include <iostream>
typedef long long ll;
using namespace std;

int T;
ll n,k,ans=0;

int main() {
    cin >> T;
    while(T--) {
        ans=0;
        cin >> n >> k;
        while(n) {
            ans+=n%k;
            n/=k;
            if (n) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
