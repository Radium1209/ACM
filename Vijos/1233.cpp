#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const double eps = 1e-10;

struct Point {
    double x, y;
    Point(double x=0, double y=0):x(x),y(y) {}
}p[100005],ch[100005];

int dcmp(double x) {
    if (fabs(x) < eps) return 0;
    else return x<0?-1:1;
}

bool operator < (const Point &a, const Point &b) {
    return a.x<b.x || (a.x==b.x && a.y<b.y);
}

typedef Point Vector;

Vector operator - (Vector A, Vector B) {
    return Vector(A.x-B.x, A.y-B.y);
}

double Cross(Vector A, Vector B) {
    return A.x*B.y - A.y*B.x;
}

double PolygonArea(Point *p, int n) {
    double area = 0.0;
    for (int i = 1; i < n-1; i++)
        area += Cross(p[i]-p[0], p[i+1]-p[0]);
    return fabs(area/2.0);
}

double Odistance(Point a, Point b) {
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

int Andrew(Point *p, int n, Point *ch) {
    sort(p, p+n);
    int m = 0;
    for (int i=0; i<n; i++) {
        while(m>1 && Cross(ch[m-1]-ch[m-2], p[i]-ch[m-2]) <= 0) m--;
        ch[m++]=p[i];
    }
    int k=m;
    for (int i=n-2; i>=0; i--) {
        while(m>k && Cross(ch[m-1]-ch[m-2], p[i]-ch[m-2]) <= 0) m--;
        ch[m++]=p[i];
    }
    if (n>1) m--;
    return m;
}

double PolygonCir(Point *p, int n) {
    double Cir = 0.0;
    for (int i = 0; i < n; i++)
        Cir += Odistance(p[i], p[(i+1)%n]);
    return Cir;
}

int main() {
    int n,m;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%lf%lf",&p[i].x,&p[i].y);
    m = Andrew(p, n, ch);

    double Area=0, Cir=0;
    Area = PolygonArea(ch, m);
    Cir = PolygonCir(ch, m);
    if (Area==0) Cir/=2.0;
    printf("%.2f\n",Cir);
    printf("%.2f\n",Area);
    return 0;
}
