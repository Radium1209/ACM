#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[105];
int odd=0,even=0;

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        if (a[i]%2) odd++;
        else even++;
    }
    printf("%d\n",min(odd,even));
    return 0;
}
