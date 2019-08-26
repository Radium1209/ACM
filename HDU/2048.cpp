#include <cstdio>
#include <iostream>
using namespace std;

int C,n;
double a[25],b[25];

int main() {
    a[1]=0; a[2]=1;
    b[1]=1; b[2]=2;
    for (int i=3;i<=25;i++) {
        a[i]=(i-1)*(a[i-1]+a[i-2]);
        b[i]=b[i-1]*i;
    }
    scanf("%d",&C);
    while(C--) {
        scanf("%d",&n);
        printf("%.2lf%%\n",a[n]/b[n]*100);
    }
    return 0;
}
