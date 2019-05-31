#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int n,ans=0;
string s;
int a[30];

int main()
{
    memset(a,0,sizeof(a));
    cin >> n;
    for (int i=0;i<n;i++)
    {
        cin >> s;
        a[s[0]-'a']++;
    }
    for (int i=0;i<26;i++)
    {
        if (a[i]/2>1)
            ans+=(a[i]/2)*(a[i]/2-1)/2;
        a[i]=a[i]-a[i]/2;
        if (a[i]>1)
            ans+=(a[i])*(a[i]-1)/2;
    }
    cout << ans << endl;
    return 0;
}
