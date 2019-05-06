#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

bool isprime(int x)
{
    if (x==1)
        return false;
    if (x==2)
        return true;
    for (int i=2;i<=sqrt(x);i++)
        if (x%i==0)
            return false;
    return true;
}

int n;

int main()
{
    while(cin >> n && n)
    {
        for (int i=3;i<=n/2;i+=2)
            if (isprime(i)&&isprime(n-i))
            {
                printf("%d = %d + %d\n",n,i,n-i);
                break;
            }
    }
    return 0;
}
