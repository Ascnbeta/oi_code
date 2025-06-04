#include <bits/stdc++.h>
#define ls p<<1
#define rs p<<1|1
typedef __int128 ll;
using namespace std;
const int maxn = 2e5+30;
int n,q;long long w;
long long a[maxn];ll val[maxn<<2],tag[maxn<<2];
inline void pushup(int p) {
    val[p] = val[ls] + val[rs];
}
inline void pushdown(int p,int l,int r) {
    int mid = (l + r) >> 1;
    val[ls] += 1ll*tag[p]*(mid-l+1);
    val[rs] += 1ll*tag[p]*(r-mid);
    tag[ls] += tag[p];
    tag[rs] += tag[p];
    tag[p] = 0;
}
inline void build(int p,int l,int r) {
    if (l == r) {
        val[p] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(p);
}
inline void modify(int p,int s,int e,ll v,int l,int r) {
    if (s <= l && r <= e) {
        val[p] += 1ll*v*(r-l+1);
        tag[p] += v;
        return;
    }
    int mid = (l + r) >> 1;
    if (l != r && tag[p]) pushdown(p,l,r);
    if (s <= mid) modify(ls,s,e,v,l,mid);
    if (e > mid) modify(rs,s,e,v,mid+1,r);
    pushup(p);
}
inline int query(int p,ll v,ll times,int l,int r) {
    if (v == 0) return l-2;
    if (l == r) {
        return l-1;
    }
    int mid = (l + r) >> 1;
    if (l != r && tag[p]) pushdown(p,l,r);
    if (val[ls]*times >= v) return query(ls,v,times,l,mid);
    else return query(rs,v-val[ls]*times,times,mid+1,r);
}
inline ll binpow(ll base,ll b) {
    ll ret = 1;
    while (b) {
        if (b&1ll) ret *= base;
        base *= base;
        b >>= 1ll;
    }
    return ret;
}
inline bool check(int x) {
    ll tmp = binpow(2,x)-1;
    if (w > tmp*val[1]) return true;
    return false;
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> q >> w;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1,1,n);
    while (q--) {
        int L,R,d;
        cin >> L >> R >> d;
        modify(1,L,R,d,1,n);
        ll sum = val[1];
        long long ret = 0;
        int l = 1,r = 64,ans = 64;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (check(mid)) {
                ans = mid;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        // cout << ans << ' ';
        ll w1 = w - sum*(binpow(2,ans)-1),times = binpow(2,ans);
        ret += ans*n;
        ret += query(1,w1,times,1,n);
        cout << ret << '\n';
    }
    return 0;
}