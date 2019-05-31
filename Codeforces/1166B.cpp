#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int flag=0;
int k,t1=0,t2=0;
char ans[10005][10005];

int main()
{
    cin >> k;
    for (int i=5;i<=sqrt(k);i++)
    {
        if (k%i==0)
        {
            flag=1;
            t1=i; t2=k/i;
            break;
        }
    }
    if (t1<5 || t2<5)
        flag=0;
    for (int i=1;i<=t1;i++)
        ans[1][i]='a';
    ans[1][2]='e'; ans[1][3]='i';
    ans[1][4]='o'; ans[1][5]='u';
    for (int i=2;i<=t2;i++)
        for (int j=1;j<=t1;j++)
            ans[i][j]=ans[i-1][j%t1+1];
    if (!flag)
        printf("-1\n");
    else
    {
        for (int i=1;i<=t2;i++)
            for (int j=1;j<=t1;j++)
                printf("%c",ans[i][j]);
    }
    return 0;
}
