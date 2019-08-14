#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int T,sx,sy,ans;
int Map[20][20];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

struct node {
    int x,y;
    int nx,ny;
    int id;
}p[20];

bool cmpx(node p1,node p2) {
    return p1.x<p2.x;
}

bool cmpy(node p1,node p2) {
    return p1.y<p2.y;
}

bool cmpid(node p1,node p2) {
    return p1.id<p2.id;
}

bool judge(int x,int y) {
    if (0<=x && x<=15 && 0<=y && y<=15)
        return true;
    return false;
}

void dfs(int x,int y) {
    Map[x][y]=1;
    for (int i=0;i<4;i++) {
        int nx=x+dx[i],ny=y+dy[i];
        if (judge(nx,ny) && !Map[nx][ny]) {
            dfs(nx,ny);
        }
    }
}

int main() {
    cin >> T;
    while(T--) {
        for (int i=1;i<=4;i++) {
            scanf("%d%d",&p[i].x,&p[i].y);
            p[i].id=i;
        }
        if (p[1].x>p[2].x) swap(p[1].x,p[2].x);
        if (p[1].y<p[2].y) swap(p[1].y,p[2].y);
        if (p[3].x>p[4].x) swap(p[3].x,p[4].x);
        if (p[3].y<p[4].y) swap(p[3].y,p[4].y);
        sort(p+1,p+4+1,cmpx);
        sx=0; sy=0;
        for (int i=1;i<=4;i++) {
            if (i==1 || p[i].x!=p[i-1].x) {
                sx+=2;
                p[i].nx=sx;
            } else {
                p[i].nx=p[i-1].nx;
            }
        }
        sort(p+1,p+4+1,cmpy);
        for (int i=1;i<=4;i++) {
            if (i==1 || p[i].y!=p[i-1].y) {
                sy+=2;
                p[i].ny=sy;
            } else {
                p[i].ny=p[i-1].ny;
            }
        }
        sort(p+1,p+4+1,cmpid);
        memset(Map,0,sizeof(Map));
        for (int i=p[1].nx;i<=p[2].nx;i++) {
            for (int j=p[2].ny;j<=p[1].ny;j++) {
            if (i==p[1].nx || i==p[2].nx || j==p[1].ny || j==p[2].ny)
                Map[i][j]=1;
            }
        }
        for (int i=p[3].nx;i<=p[4].nx;i++) {
            for (int j=p[4].ny;j<=p[3].ny;j++) {
                if (i==p[3].nx || i==p[4].nx || j==p[3].ny || j==p[4].ny)
                    Map[i][j]=1;
            }
        }
        ans=0;
        for (int i=1;i<=15;i++) {
            for (int j=1;j<=15;j++) {
                if (!Map[i][j]) {
                    dfs(i,j);
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
