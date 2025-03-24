#include <bits/stdc++.h>
#define ls p<<1
#define rs p<<1|1
#define int long long
using namespace std;
const int maxn = 1e6+30;
int T;
int n,m;
int a[maxn];
int val[maxn],sum[maxn],cnt[maxn],se[maxn],tag[maxn];
inline void pushup(int p) {
    if (val[ls] == val[rs]) {
        val[p] = val[ls],cnt[p] = cnt[ls] + cnt[rs];
        se[p] = max(se[ls],se[rs]);
    }else{
        if (val[ls] > val[rs]) {
            val[p] = val[ls],cnt[p] = cnt[ls];
            se[p] = max(se[ls],val[rs]);
        }else{
            val[p] = val[rs],cnt[p] = cnt[rs];
            se[p] = max(se[rs],val[ls]);
        }
    }
    sum[p] = sum[ls] + sum[rs];
}
inline void build(int p,int l,int r) {
    tag[p] = -1;
    if (l == r) {
        sum[p] = val[p] = se[p] = a[l];
        cnt[p] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(p);
    return;
}
inline void modify(int p,int v,int s,int e,int l,int r) {
    if (s <= l && r <= e) {
        if (v >= val[p]) return;
        else if(se[p] < v) {
            if (tag[p] != -1) {
                tag[p] = min(tag[p],v);
                sum[p] += cnt[p] * (v-val[p]) * cnt[p];
                cnt[p] 
            }
        }
    }
}
signed main() {
#ifdef LOCAL
    freopen("E:/codes/exe/a.in","r",stdin);
    freopen("E:/codes/exe/a.out","w",stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> a[i];
        build(1,1,n);
        while (m--) {
            int opt;
            cin >> opt;
            if (opt == 1) {
                int l,r,t;
                cin >> l >> r >> t;
                modify(1,t,l,r,1,n);
            }
        }
    }
    return 0;
}