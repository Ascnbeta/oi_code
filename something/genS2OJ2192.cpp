#include <bits/stdc++.h>
using namespace std;

int main () {
    freopen("D:/codes/exe/a.in","w",stdout);
    int n = 100000;
    cout << n << '\n';
    for (int i = 1; i <= n; i++) {
        if (i != n) cout << 99991 << ' ';
        else cout << 99991;
    }
    cout << '\n';
    return 0;
}