#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,ans;
struct cake{
    int x,y;
}c[200005];
signed main () {
    cin >> n >> m;
    cin >> k;
    for (int i = 1; i <= k; i++) {
        cin >> c[i].x >> c[i].y;
        if (c[i].y >= c[i].x) ++ans;
    }
    cout << ans << endl;
    return 0;
}