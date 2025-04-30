#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e5+30;
int n,n1,v,ans;
struct goal{
    int t,a;
    bool operator < (const goal &y) const{
        if (v*t+a == v*y.t+y.a) return v*t-a<v*y.t-y.a;
        return v*t+a < v*y.t+y.a;
    }
}g[maxn];
int f[maxn],b[maxn];
int t[maxn];
inline int lowbit(int x) {
    return x&-x;
}
inline void modify(int p,int x) {
    while (p <= n1) {
        t[p] = max(t[p],x);
        p += lowbit(p);
    }
}
inline int query(int p) {
    int ret = 0xcfcfcfcfcfcfcfcf;
    while (p > 0) {
        ret = max(t[p],ret);
        p -= lowbit(p);
    }
    return ret;
}
signed main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> v;
    for (int i = 1; i <= n; i++) cin >> g[i].t;
    for (int i = 1; i <= n; i++) cin >> g[i].a;
    g[n+1] = {0,0};
    
    for (int i = 1; i <= n+1; i++) b[i] = v*g[i].t-g[i].a;
    sort(b+1,b+n+2);
    n1 = unique(b+1,b+n+2)-b-1;
    sort(g+1,g+n+2);
    memset(t,0xc0,sizeof(t));
    for (int i = 1; i <= n+1; i++) {

        int x = lower_bound(b+1,b+n1+1,v*g[i].t-g[i].a)-b;
        f[i] = query(x)+1;
        if (v*g[i].t-g[i].a == 0 && v*g[i].t+g[i].a == 0) f[i] = 0;
        modify(x,f[i]);
        ans = max(f[i],ans);
    }
    cout << ans << '\n';
    return 0;
}