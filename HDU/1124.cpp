#include <cstdio>
#include <iostream>
using namespace std;

int T,N;

int Z(int n)
{
    int t=5,ret=0;
    while(n/t)
    {
        ret+=n/t;
        t*=5;
    }
    return ret;
}

int main()
{
    cin >> T;
    while(T--)
    {
        scanf("%d",&N);
        printf("%d\n",Z(N));
    }
    return 0;
}
