#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+30;
const int maxm = 1e5+30;
int n,m;
int d[maxn],t[maxm];
struct subject{
    int t,id,chk;
    bool operator < (const subject &y) const{
        return t < y.t;
    }
}s[maxn];
inline bool check(int x) {
    int cnt = 0;
    for (int i = x; i >= 1; i--) {
        if (d[i] && s[d[i]].chk != x) {
            s[d[i]].t = i,s[d[i]].id = d[i],s[d[i]].chk = x;
            ++cnt;
        }
    }
    if (cnt < m) return false;
    sort(s+1,s+m+1);
    int cur = 0;cnt = 0;
    for (int i = 1; i <= m; i++) {
        while (cur < s[i].t && cur < n) {
            ++cur;
            if (cur != s[i].t) ++cnt;
        }
        if (cnt < t[s[i].id]) return false;
        cnt -= t[s[i].id];
    }
    return true;
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> d[i];
    for (int i = 1; i <= m; i++) cin >> t[i];
    int l = 1,r = n,ans = r+1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        }else {
            l = mid + 1;
        }
    }
    if (ans > n) puts("-1");
    else printf("%d",ans);
    return 0;
}