#include <bits/stdc++.h>
#define int long long
#define ls p<<1
#define rs p<<1|1
using namespace std;
const int maxn = 5e5+20;
int n,m,k;
int val[maxn<<2],tag[maxn<<2],cnt[maxn<<2];
struct line{
    int l,r,w;
    bool operator < (const line &y) const {
        return w > y.w;
    }
}p[maxn];
inline void pushup(int p) {
    val[p] = max(val[ls],val[rs]);
    cnt[p] = cnt[ls] + cnt[rs];
}
inline void pushdown(int p,int l,int r) {
    int mid = (l + r) >> 1;
    if (cnt[ls] != mid - l + 1) val[ls] = max(val[ls],tag[p]),cnt[ls] = mid - l + 1,tag[ls] = max(tag[ls],tag[p]);
    if (cnt[rs] != r - mid) val[rs] = max(val[rs],tag[p]),cnt[rs] = r - mid,tag[rs] = max(tag[rs],tag[p]);
    tag[p] = 0;
}
inline void modify(int p,int v,int s,int e,int l,int r) {
    if (cnt[p] == r - l + 1) return;
    if (s <= l && r <= e) {
        val[p] = max(val[p],v);
        tag[p] = max(v,tag[p]);
        return;
    }
    int mid = (l + r) >> 1;
    if (l != r && tag[p]) pushdown(p,l,r);
    if (s <= mid) modify(ls,v,s,e,l,mid);
    if (e > mid) modify(rs,v,s,e,mid+1,r);
    pushup(p);
}
inline int query(int p,int pos,int l,int r) {
    if (l == r) {
        return val[p];
    }
    int mid = (l + r) >> 1;
    if (l != r && tag[p]) pushdown(p,l,r);
    if (pos <= mid) return query(ls,pos,l,mid);
    else return query(rs,pos,mid+1,r);
}
int f[maxn];
priority_queue<int> q;
signed main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].l >> p[i].r >> p[i].w;
        p[i].r -= k-1;
    }
    sort(p+1,p+n+1);
    for (int i = 1; i <= n; i++) {
        if (p[i].l > p[i].r) continue;
        modify(1,p[i].w,p[i].l,p[i].r,1,m);
    }
    for (int i = 1; i <= m; i++) {
        if (i >= k) {
            q.push(f[i-k]+query(1,i-k+1,1,m));
        }
        q.push(f[i-1]);
        if (!q.empty()) f[i] = q.top();
    }
    // for (int i = 1; i <= m; i++) {
    //     cout << query(1,i,1,m) << ' ';
    // }
    // cout << '\n';
    // for (int i = 1; i <= m; i++) {
    //     cout << f[i] << ' ';
    // }
    // cout << '\n';
    cout << f[m] << '\n';
    return 0;
}