#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int x1,x2,x3,x4,y1,y2,y3,y4;
int uu,dd,ll,rr,u,d,l,r;
int flag=true;

int main()
{
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
    rr=max(x1,max(x2,max(x3,x4)));
    ll=min(x1,min(x2,min(x3,x4)));
    dd=min(y1,min(y2,min(y3,y4)));
    uu=max(y1,max(y2,max(y3,y4)));
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
    r=max(x1,max(x2,max(x3,x4)));
    l=min(x1,min(x2,min(x3,x4)));
    u=max(y1,max(y2,max(y3,y4)));
    d=min(y1,min(y2,min(y3,y4)));
    int t=1,st=(l+r)/2;
    for (int i=d;i<=(u+d)/2;i++)
    {
        for (int j=st;j<st+t;j++)
        {
            if (ll<=j && j<=rr && dd<=i && i<=uu)
            {
                flag=false;
            }
        }
        t+=2; st--;
    }
    t=1,st=(l+r)/2;
    for (int i=u;i>=(u+d)/2+1;i--)
    {
        for (int j=st;j<st+t;j++)
        {
            if (ll<=j && j<=rr && dd<=i && i<=uu)
            {
                flag=false;
            }
        }
        t+=2; st--;
    }
    if (flag)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
    return 0;
}
