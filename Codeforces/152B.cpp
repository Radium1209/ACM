#include <cstdio>
#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

ll ans=0;
int n,m,xc,yc,k,dx,dy,tx,ty,t;

int main() {
    cin >> n >> m >> xc >> yc >> k;
    for (int i=1;i<=k;i++) {
        scanf("%d%d",&dx,&dy);
        if (dx==0) {
            tx=2e9+5;
        } else if (dx<0) {
            tx=(xc-1)/(-dx);
        } else {
            tx=(n-xc)/dx;
        }
        if (dy==0) {
            ty=2e9+5;
        } else if (dy<0) {
            ty=(yc-1)/(-dy);
        } else {
            ty=(m-yc)/dy;
        }
        t=min(tx,ty);
        xc+=dx*t;
        yc+=dy*t;
        ans+=(ll)t;
    }
    cout << ans << endl;
    return 0;
}
