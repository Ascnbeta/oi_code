#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e5+10;
int n,a[maxn],lst[maxn];
int t[maxn];
int ans;
inline int lowbit(int x) {
    return x & (-x);
}
inline void modify(int p,int x) {
    while (p <= maxn-5) {
        t[p] += x;
        p += lowbit(p);
    }
}
inline int query(int p) {
    int ret = 0;
    while (p > 0) {
        ret += t[p];
        p -= lowbit(p);
    }
    return ret;
}
signed main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[n+1-i];
    for (int i = 1; i <= n; i++) {
        if (lst[a[i]] == 0) {
            modify(i,i);
            ans += query(i);
            lst[a[i]] = i;
        }else{
            modify(lst[a[i]],-lst[a[i]]);
            modify(i,i);
            ans += query(i);
            lst[a[i]] = i;
        }
    }
    cout << ans << '\n';
    return 0;
}