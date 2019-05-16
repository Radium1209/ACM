#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int n,temp=1,ans=0;
int a[200005];

int main()
{
    cin >> n;
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++)
    {
        if (temp<=a[i])
        {
            ans++;
            temp++;
        }
    }
    cout << ans << endl;
    return 0;
}
