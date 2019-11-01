#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const double eps = 1e-10;

int n;

struct Point {
    double x, y;
    Point(double x=0, double y=0):x(x),y(y) {} // 构造函数
}p[705];

typedef Point Vector;

Vector operator - (Vector A, Vector B) {
    return Vector(A.x-B.x, A.y-B.y);
}

int dcmp(double x) {
    if (fabs(x) < eps) return 0;
    else return x<0?-1:1;
}

double Cross(Vector A, Vector B) {
    return A.x*B.y - A.y*B.x;
}

double Dot(Vector A, Vector B) {
    return A.x*B.x + A.y*B.y;
}

bool OnSegment(Point p, Point a1, Point a2) {
    return dcmp(Cross(a1-p, a2-p))==0 && dcmp(Dot(a1-p, a2-p)) < 0;
}

int main() {
    int ans=0;
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        scanf("%lf%lf",&p[i].x,&p[i].y);
    }
    for (int i=1;i<=n;i++) {
        for (int j=i+1;j<=n;j++) {
            int sum=0;
            for (int k=1;k<=n;k++) {
                if (k==i || k==j) continue;
                if (OnSegment(p[k],p[i],p[j]))
                    sum++;
            }
            ans=max(ans,sum);
        }
    }
    printf("%d\n",ans+2);
    return 0;
}
