#include <bits/stdc++.h>
#define int long long
using namespace std;
int k,a,b;
signed main () {
    cin >> k;
    if (k == 1) {
        cout << 1 << ' ' << 1 << '\n';
        return 0;
    }
    a = 2,b = 2;
    for (int i = 1 ; i <= k; i++) {
        int x = a+b,y = a;
        a = x,b = y;
    }
    cout << a << ' ' << b << '\n';
    return 0;
}