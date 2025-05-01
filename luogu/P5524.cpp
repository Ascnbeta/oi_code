#include <bits/stdc++.h>
#define ls p<<1
#define rs p<<1|1
using namespace std;
const int maxn = 1e6+50;
int n,m,q;
int op[maxn];
int val[maxn<<2],tim[maxn<<2],tagx[maxn<<2],tagt[maxn<<2];
inline void pushdown(int p) {
    tim[ls] = tim[rs] = tagt[p];
    tagt[ls] = tagt[rs] = tagt[p];
    tagt[p] = 0;
    val[ls] = val[rs] = tagx[p];
    tagx[ls] = tagx[rs] = tagx[p];
    tagx[p] = 0;
}
inline void modify(int p,int s,int e,int v,int t,int l,int r) {
    if (s <= l && r <= e) {
        val[p] = v,tagx[p] = v;
        tim[p] = t,tagt[p] = t;
        return;
    }
    int mid = (l + r) >> 1;
    if (l != r && (tagx[p] || tagt[p])) pushdown(p);
    if (s <= mid) modify(ls,s,e,v,t,l,mid);
    if (e > mid) modify(rs,s,e,v,t,mid+1,r);
}
inline pair<int,int> query(int p,int pos,int l,int r) {
    if (l == r) {
        return {val[p],tim[p]};
    }
    int mid = (l + r) >> 1;
    if (l != r && (tagx[p] || tagt[p])) pushdown(p);
    return (pos<=mid)?(query(ls,pos,l,mid)):(query(rs,pos,mid+1,r));
}
int t[maxn],v[maxn];
struct ask{
    long long l,r,ans,id;
}a[maxn];
bool cmp1 (const ask &x,const ask &y) {
    return x.r < y.r;
}
bool cmp2 (const ask &x,const ask &y) {
    return x.id < y.id;
}
long long tr[maxn];
inline void modify(int p,int x) {
    if (p == 0) return;
    while (p <= m) {
        tr[p] += x;
        p += (p&-p);
    }
}
inline long long query(int p) {
    long long ret = 0;
    while (p > 0) {
        ret += tr[p];
        p -= (p&-p);
    }
    return ret;
}
signed main () {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m >> q;
    for (int i = 1 ; i <= m; i++) {
        cin >> op[i];
        if (op[i] == 1) {
            int x,y;
            cin >> x >> y;
            pair<int,int> t1 = query(1,x,1,n),t2 = query(1,y,1,n);
            modify(1,y,y,t1.first,t1.second,1,n);
            modify(1,x,x,t2.first,t2.second,1,n);
        }else if (op[i] == 2) {
            int l,r,x;
            cin >> l >> r >> x;
            modify(1,l,r,x,i,1,n);
        }else{
            int x;
            cin >> x;
            pair<int,int> tmp = query(1,x,1,n);
            v[i] = tmp.first,t[i] = tmp.second;
            if (t[i] == 0) op[i] = 0;
        }
    }
    for (int i = 1; i <= q; i++) cin >> a[i].l >> a[i].r,a[i].id = i;
    sort(a+1,a+q+1,cmp1);
    int lst = 1;
    for (int i = 1; i <= m; i++) {
        while (a[lst].r <= i-1 && lst <= q) a[lst].ans = query(a[lst].r) - query(a[lst].l-1),++lst;
        if (op[i] == 3) {
            modify(t[i],v[i]);
        }
        while (a[lst].r <= i && lst <= q) a[lst].ans = query(a[lst].r) - query(a[lst].l-1),++lst;
    }
    sort(a+1,a+q+1,cmp2);
    for (int i = 1; i <= q; i++) cout << a[i].ans << '\n';
    return 0;
}