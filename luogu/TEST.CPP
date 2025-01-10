#include <bits/stdc++.h>
using namespace std;
int n,m;
int main () {
    cin >> m >> n;
    double tmp = m * 1.0 / n;
    int ret = ceil(tmp);
    for (int i = 1; i <= 20; i++) {
        cout << ret << ' ';
        m = n;
        n = ret;
        tmp = m * 1.0 / n;
        ret = ceil(tmp);
    }
    return 0;
}