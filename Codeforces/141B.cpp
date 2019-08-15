#include <cstdio>
#include <iostream>
using namespace std;

double a,x,y,ty;
int ans=-1,p;

int main() {
    cin >> a >> x >> y;
    if (-(a/2.0)<x && x<a/2.0 && 0.0<y && y<a) {
        ans=1;
    }
    ty=a; p=2;
    while(ty<=y) {
        if (p%3==2) {
            if (-(a/2.0)<x && x<a/2.0 && ty<y && y<ty+a)
                ans=p;
            ty+=a;
        } else if (p%3==0) {
            if (-a<x && x<0.0 && ty<y && y<ty+a)
                ans=p;
        } else {
            if (0.0<x && x<a && ty<y && y<ty+a)
                ans=p;
            ty+=a;
        }
        p++;
    }
    cout << ans << endl;
    return 0;
}
