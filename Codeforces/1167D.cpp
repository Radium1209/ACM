#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int n,t=0,t0=0,t1=0;
string s;

int main()
{
    cin >> n >> s;
    for (int i=0;i<s.length();i++)
    {
        if (s[i]=='(')
        {
            if (i!=0 && s[i-1]=='(')
            {
                if (t==0)
                {
                    t++; t1++;
                    printf("%d",t);
                }
                else
                {
                    t--; t0++;
                    printf("%d",t);
                }
            }
            else
            {
                if (t==0)
                    t0++;
                else
                    t1++;
                printf("%d",t);
            }
        }
        else
        {
            if (t==0 && t0!=0)
            {
                t0--; t++;
                printf("0");
            }
            else if (t==1 && t1!=0)
            {
                t1--; t--;
                printf("1");
            }
            else if (t0!=0)
            {
                t0--; t++;
                printf("0");
            }
            else if (t1!=0)
            {
                t1--; t--;
                printf("1");
            }
        }
    }
    return 0;
}
