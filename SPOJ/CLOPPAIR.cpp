#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#define MAXN 50005
typedef long long ll;
using namespace std;

struct Point {
    int x, y, id;
};

bool cmpx(Point p1, Point p2) {
    if (p1.x==p2.x) return p1.y<p2.y;
    return p1.x<p2.x;
}

bool cmpy(Point p1, Point p2) {
    return p1.y<p2.y;
}

double Odistance(Point p1, Point p2) {
    return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}

int n;
Point p[MAXN];
double minDis;
int ansa, ansb;

void updateAns(Point p1, Point p2) {
    double Dis=Odistance(p1, p2);
    if (Dis<minDis) minDis=Dis,ansa=p1.id,ansb=p2.id;
}

void rec(int l, int r) {
    if (r-l<=3) {
        for (int i=l; i<=r; i++)
            for (int j=i+1; j<=r; j++)
                updateAns(p[i], p[j]);
        sort(p+l, p+r+1, cmpy);
        return;
    }

    int m=(l+r)>>1;
    int midx=p[m].x;
    rec(l,m), rec(m+1,r);
    static Point t[MAXN];
    merge(p+l, p+m+1, p+m+1, p+r+1, t, cmpy);
    copy(t, t+r-l+1, p+l);

    int tsz=0;
    for (int i=l; i<=r; i++) {
        if (abs(p[i].x-midx) < minDis) {
            for (int j=tsz-1; j>=0 && p[i].y-t[j].y<minDis; j--)
                updateAns(p[i], t[j]);
            t[tsz++]=p[i];
        }
    }
}

int main() {
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d %d",&p[i].x, &p[i].y);
        p[i].id=i;
    }
    sort(p, p+n, cmpx);
    minDis=1E20;
    rec(0, n-1);
    if (ansa>ansb) swap(ansa, ansb);
    printf("%d %d %.6f\n",ansa, ansb, minDis);
    return 0;
}
