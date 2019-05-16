#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int t,flag;
int a1,a2,a3,a4,a5,a6;
int a[6]={4,8,15,16,23,42};
int vis[6];

int main()
{
    printf("? 1 2\n");
    cin >> t;
    flag=true;
    for (int i=0;i<6&&flag;i++)
    {
        for (int j=0;j<6;j++)
        {
            if (i!=j && a[i]*a[j]==t)
            {
                a1=a[i];
                a2=a[j];
                flag=false;
                break;
            }
        }
    }
    printf("? 2 3\n");
    cin >> t;
    flag=true;
    for (int i=0;i<6&&flag;i++)
    {
        for (int j=0;j<6;j++)
        {
            if (i!=j && a[i]*a[j]==t)
            {
                if (a[i]*a1==t || a[j]*a1==t)
                    swap(a1,a2);
                a3=t/a2;
                flag=false;
                break;
            }
        }
    }
    printf("? 4 5\n");
    cin >> t;
    flag=true;
    for (int i=0;i<6&&flag;i++)
    {
        for (int j=0;j<6;j++)
        {
            if (i!=j && a[i]*a[j]==t)
            {
                a4=a[i];
                a5=a[j];
                flag=false;
                break;
            }
        }
    }
    printf("? 5 6\n");
    cin >> t;
    flag=true;
    for (int i=0;i<6&&flag;i++)
    {
        for (int j=0;j<6;j++)
        {
            if (i!=j && a[i]*a[j]==t)
            {
                if (a[i]*a4==t || a[j]*a4==t)
                    swap(a4,a5);
                a6=t/a5;
                flag=false;
                break;
            }
        }
    }
    printf("! %d %d %d %d %d %d\n",a1,a2,a3,a4,a5,a6);
    return 0;
}
