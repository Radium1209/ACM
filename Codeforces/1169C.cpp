#include <cstdio>
#include <iostream>
using namespace std;

int n,m;
int a[300005];
int b[300005];

int judge(int k)
{
    b[0]=0;
    for (int i=1;i<=n;i++)
    {
        if (b[i-1]>=a[i])
        {
            if (a[i]+k>=b[i-1])
                b[i]=b[i-1];
            else
                return 0;
        }
        else
        {
            if (a[i]+k>=m && (a[i]+k)%m>=b[i-1])
            {
                b[i]=b[i-1];
            }
            else
                b[i]=a[i];
        }
    }
    return 1;
}

int main()
{
    a[0]=0;
    cin >> n >> m;
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int l=0,r=m,mid;
    while(l<r)
    {
        mid=(l+r)>>1;
        if (judge(mid))
            r=mid;
        else
            l=mid+1;
    }
    cout << l << endl;
    return 0;
}
