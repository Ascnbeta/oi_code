#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
const int maxn = 3e6+30;
int n,m;
long long ans;
int tot,rt;
vector<int> val(maxn<<1),ls(maxn<<1),rs(maxn<<1);
inline void build(int &p,int l,int r) {
    if (!p) p = ++tot;
    if (l == r) {
        val[p] = l;
        return;
    }
    int mid = (l + r) >> 1;
    build(ls[p],l,mid);
    build(rs[p],mid+1,r);
    val[p] = max(val[ls[p]],val[rs[p]]);
}
inline void modify(int &p,int pos,int l,int r) {
    if (!p) p = ++tot;
    if (l == r) {
        val[p] = 0;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) modify(ls[p],pos,l,mid);
    else modify(rs[p],pos,mid+1,r);
    val[p] = max(val[ls[p]],val[rs[p]]);
}
inline int query(int &p,int s,int e,int l,int r) {
    if (!p) return 0;
    if (s <= l && r <= e) {
        return val[p];
    }
    int mid = (l + r) >> 1;
    int ret = 0;
    if (s <= mid) ret = max(ret,query(ls[p],s,e,l,mid));
    if (e > mid) ret = max(ret,query(rs[p],s,e,mid+1,r));
    return ret;
}
signed main() {
#ifdef LOCAL
    freopen("E:/codes/exe/a.in","r",stdin);
    freopen("E:/codes/exe/a.out","w",stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    build(rt,1,m);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        int t = query(rt,1,x,1,m);
        // cout << t << '\n';
        ans = (ans + (long long)t*i %mod)%mod;
        modify(rt,t,1,m);
    }
    cout << ans << '\n';
    return 0;
}