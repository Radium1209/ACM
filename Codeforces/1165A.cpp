#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int ans=0,n,x,y;
string s;

int main()
{
    cin >> n >> x >> y >> s;
    for (int i=n-1;i>=n-x;i--)
        if (s[i]=='1' && i!=n-y-1)
            ans++;
    if (s[n-y-1]!='1')
        ans++;
    cout << ans << endl;
    return 0;
}
