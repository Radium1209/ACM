#include <cstdio>
#include <iostream>
#include <cmath>
typedef long long ll;
using namespace std;

ll n,k,x;

int main() {
    cin >> n >> k;
    x=(-3+sqrt(9+8*(n+k)))/2;
    cout << n-x << endl;
    return 0;
}
