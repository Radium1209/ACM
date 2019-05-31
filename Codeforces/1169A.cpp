#include <cstdio>
#include <iostream>
using namespace std;

int n,a,x,b,y;
int flag=0;

int main()
{
    cin >> n >> a >> x >> b >> y;
    for (int i=1;i<=n;i++)
    {
        if (a==b)
        {
            flag=1;
            break;
        }
        if (a==x || b==y)
            break;
        a=a%n+1;
        b=b-1; if (b==0) b=n;
    }
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
