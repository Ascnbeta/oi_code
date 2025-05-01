#include <bits/stdc++.h>
#define ls p<<1
#define rs p<<1|1
using namespace std;
const int maxn = 1e5+30;
const int maxm = 5e4+40;
int n,m;
string s;
int op[maxm],l[maxm],r[maxm];
char ans[maxn];
int val[maxn<<2],tag[maxn<<2];
inline void pushup(int p) {
    val[p] = val[ls] + val[rs];
}
inline void pushdown(int p,int l,int r) {
    int mid = (l + r) >> 1;
    val[ls] = tag[p]*(mid-l+1);
    val[rs] = tag[p]*(r-mid);
    tag[ls] = tag[rs] = tag[p];
    tag[p] = -1;
}
inline void build(int p,int l,int r,int cnt) {
    tag[p] = -1;
    if (l == r) {
        if (s[l] <= cnt+'a') val[p] = 0;
        else val[p] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(ls,l,mid,cnt);
    build(rs,mid+1,r,cnt);
    pushup(p);
}
inline void modify(int p,int s,int e,int v,int l,int r) {
    if (s > e) return;
    if (s <= l && r <= e) {
        val[p] = (r-l+1)*v;
        tag[p] = v;
        return;
    }
    int mid = (l + r) >> 1;
    if (tag[p] != -1 && l != r) pushdown(p,l,r);
    if (s <= mid) modify(ls,s,e,v,l,mid);
    if (e > mid) modify(rs,s,e,v,mid+1,r);
    pushup(p);
}
inline int query(int p,int s,int e,int l,int r) {
    if (s <= l && r <= e) return val[p];
    int mid = (l + r) >> 1;
    if (tag[p] != -1 && l != r) pushdown(p,l,r);
    int ret = 0;
    if (s <= mid) ret += query(ls,s,e,l,mid); 
    if (e > mid) ret += query(rs,s,e,mid+1,r);
    return ret;
}
inline void solve(int p,int l,int r,int cnt) {
    if (l == r) {
        if (val[p] == 0 && ans[l] == 0) ans[l] = cnt+'a';
        return;
    }
    int mid = (l + r) >> 1;
    if (tag[p] != -1 && l != r) pushdown(p,l,r);
    solve(ls,l,mid,cnt);
    solve(rs,mid+1,r,cnt);
}
int main () {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> m >> s;
    s = ' ' + s;
    for (int i = 1; i <= m; i++) cin >> l[i] >> r[i] >> op[i];
    for (int i = 0; i <= 25; i++) {
        build(1,1,n,i);

        for (int j = 1; j <= m; j++ ) {
            if (op[j] == 1) {
                int tmp = query(1,l[j],r[j],1,n);
                modify(1,l[j],r[j]-tmp,0,1,n);
                modify(1,r[j]-tmp+1,r[j],1,1,n);
            }else{
                int tmp = query(1,l[j],r[j],1,n);
                modify(1,l[j],l[j]+tmp-1,1,1,n);
                modify(1,l[j]+tmp,r[j],0,1,n);
            }
        }
        solve(1,1,n,i);
    }
    for (int i = 1; i <= n; i++) cout << ans[i];
    cout << '\n';
    return 0;
}