#include <bits/stdc++.h>
#define ls p<<1
#define rs p<<1|1
using namespace std;
const int maxn = 2e5+30;
const int maxv = 2e5+3;
int n,m;
// int a[maxn];
array<int,maxn> a;
array<int,maxn<<2> val;
struct ask{
    int l,r,ans,id;
    ask() {
        l = r = ans = id = 0;
    }
};
// ask q[maxn];
array<ask,maxn> q;
bool cmp1 (ask x,ask y) {
    return x.r < y.r;
}
bool cmp2 (ask x,ask y) {
    return x.id < y.id;
}
inline void pushup(int p) {
    val[p] = min(val[ls],val[rs]);
}
inline void modify(int p,int pos,int v,int l,int r) {
    if (l == r) {
        val[p] = v;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) modify(ls,pos,v,l,mid);
    else modify(rs,pos,v,mid+1,r);
    pushup(p);
}
inline int query(int v) {
    int p = 1,l = 0,r = maxv;
    while (1) {
        if (l == r) return l;
        int mid = (l + r) >> 1;
        if (v > val[ls]) p = ls,r = mid;
        else if (v > val[rs]) p = rs,l = mid + 1;
        else assert(0);
    }
}
inline int query(int p,int pos,int l,int r) {
    if (l == r) {
        return val[p];
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) return query(ls,pos,l,mid);
    else return query(rs,pos,mid+1,r);
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> q[i].l >> q[i].r,q[i].id = i;
    sort(q.begin()+1,q.begin()+m+1,cmp1);
    int lst = 0;
    for (int i = 1; i <= m; i++) {
        while (lst < q[i].r) {
            ++lst;
            modify(1,a[lst],lst,0,maxv);
        }
        // cout << query(1,2,0,maxv) << '\n';
        q[i].ans = query(q[i].l);
        // cout << q[i].l << ' ' << q[i].r << ' ' << q[i].ans << '\n';
    }
    sort(q.begin()+1,q.begin()+m+1,cmp2);
    for (int i = 1; i <= m; i++) {
        cout << q[i].ans << '\n';
    }
    return 0;
}