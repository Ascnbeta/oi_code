#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5+20;
int n,m,k;
struct obj{
    int id,p,f;
    bool operator < (const obj &y) const{
        return p < y.p;
    }
}a[maxn];
bool f[maxn];
inline bool check(int x) {
    for (int i = 1; i <= n; i++) f[i] = false;
    int cnt = 0,tot = 0,cst = 0;
    for (int i = 1; i <= 2*n; i++) {
        if (f[a[i].id]) continue;
        if (a[i].f && cnt == k) continue;
        ++tot,cst += a[i].p;
        if (a[i].f) cnt++;
        f[a[i].id] = true;
        if (tot == x || cst > m) break;
    }
    if (tot == x && cst <= m) return true;
    else return false;
}
signed main () {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/wt.out","w",stdout);
#endif
    cin >> n >> k >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].p >> a[i+n].p;
        a[i].id = a[i+n].id = i;
        a[i+n].f = 1;
    }
    sort(a+1,a+2*n+1);
    // for (int i = 1; i <= n; i++) cout << a[i].p << ' ';
    // cout << '\n';
    int l = 1,r = n,ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        // cout << mid << '\n';
        if (check(mid)) {
            l = mid + 1;
            ans = mid;
        }else{
            r = mid - 1;
        }
    }
    cout << ans << '\n';
    return 0;
}
/*
8 1 24
6 3
9 8
9 6
13 2
14 12
5 1
12 4
9 7
*/