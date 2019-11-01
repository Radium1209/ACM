#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    double x, y;
    Point(double x=0, double y=0):x(x),y(y) {} // 构造函数
};

double Odistance(Point a, Point b) {
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

int main() {
    double a,b,c,d;
    scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
    Point p1(-a,-sqrt(b)), p2(-c,sqrt(d));
    printf("%.3lf\n",Odistance(p1, p2));
    return 0;
}
