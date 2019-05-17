#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int n,k=0;
int p1,p2;
string s,ans="";

int main()
{
    cin >> n >> s;
    if (s.length()<=1)
    {
        printf("%d\n\n",n);
        return 0;
    }
    p1=0;p2=1;
    while(p1<n && p2<n)
    {
        if (s[p1]!=s[p2])
        {
            k+=2;
            ans+=s[p1];
            ans+=s[p2];
            p1=p2+1;
            p2=p1+1;
            if (p2>=n)
                break;
        }
        else
            p2++;
    }
    cout << n-k << endl;
    cout << ans << endl;
    return 0;
}
