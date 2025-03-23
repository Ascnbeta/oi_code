#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+30;
int n,m;
int a[maxn],b[maxn],rt[maxn];
int ls[maxn<<5],rs[maxn<<5],cnt[maxn<<5],tot;
inline int build(int l,int r) {
    int u = ++tot;
    cnt[u] = 0;
    if (l < r) {
        int mid = (l + r) >> 1;
        ls[u] = build(l,mid);
        rs[u] = build(mid+1,r);
    }
    return u;
}
inline int insert(int p,int v,int l,int r) {
    int u = ++tot;
    ls[u] = ls[p],rs[u] = rs[p],cnt[u] = cnt[p] + 1;
    if (l < r) {
        int mid = (l + r) >> 1;
        if (v <= mid) {
            ls[u] = insert(ls[u],v,l,mid);
        }else{
            rs[u] = insert(rs[u],v,mid+1,r);
        }
    }
    return u;
}
inline int query(int u,int v,int l,int r,int k) {
    if (l == r) return l;
    int x = cnt[ls[v]] - cnt[ls[u]];
    int mid = (l + r) >> 1;
    if (x >= k) {
        return query(ls[u],ls[v],l,mid,k);
    }else{
        return query(rs[u],rs[v],mid+1,r,k-x);
    }
}
int main() {
#ifdef LOCAL
    freopen("E:/codes/exe/a.in","r",stdin);
    freopen("E:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i],b[i] = a[i];
    sort(b+1,b+n+1);
    
    int n1 = unique(b+1,b+n+1)-b-1;
    rt[0] = build(1,n1);
    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(b+1,b+n1+1,a[i])-b;
        rt[i] = insert(rt[i-1],a[i],1,n1);
    }
    while (m--) {
        int l,r,k;
        cin >> l >> r >> k;
        cout << b[query(rt[l-1],rt[r],1,n1,k)] << '\n';
    }
    return 0;
}