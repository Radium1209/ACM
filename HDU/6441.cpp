#include <cstdio>
#include <iostream>
typedef long long ll;
using namespace std;

ll a,b,c,n,T,x,y;

int main() {
    cin >> T;
    while(T--) {
        b=c=-1;
        scanf("%lld%lld",&n,&a);
        if (n==1) {
            b=1; c=a+1;
        } else if (n==2) {
            if (a%2) x=1,y=a*a;
            else x=2,y=a*a/2;
            b=(y-x)/2;
            c=(y+x)/2;
        }
        printf("%lld %lld\n",b,c);
    }
    return 0;
}
