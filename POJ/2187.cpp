#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#define MAXN 500005
using namespace std;

struct Point {
    int x, y;
    Point(int x=0, int y=0):x(x),y(y) {}
}p[MAXN],ch[MAXN];

typedef Point Vector;

bool operator < (const Point &a, const Point &b) {
    return a.x<b.x || (a.x==b.x && a.y<b.y);
}

Vector operator - (Vector A, Vector B) {
    return Vector(A.x-B.x, A.y-B.y);
}

int Cross(Vector A, Vector B) {
    return A.x*B.y - A.y*B.x;
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

int Odistance2(Point a, Point b) {
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

int RotCal(Point* ch, int m) {
    ch[m]=ch[0]; int j=1;
    int ret=0;
    for(int i=0 ;i<m; i++) {
        while(abs(Cross(ch[i]-ch[j],ch[i+1]-ch[j]))<abs(Cross(ch[i]-ch[j+1],ch[i+1]-ch[j+1]))) {
            j=(j+1)%m;
        }
        ret=max(ret,Odistance2(ch[i], ch[j]));
    }
    return ret;
}

int main() {
    int n;
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d %d",&p[i].x, &p[i].y);
    }
    int m=Andrew(p,n,ch);
    cout << RotCal(ch,m) << endl;
    return 0;
}
