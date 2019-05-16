#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int t,n,pos;
string s;

int main()
{
    cin >> t;
    while(t--)
    {
        cin >> n >> s;
        pos=n+1;
        for (int i=0;i<n;i++)
            if (s[i]=='8')
            {
                pos=i;
                break;
            }
        if (n-pos>=11)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
