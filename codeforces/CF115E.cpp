#include <bits/stdc++.h>
#define int long long
#define ls p<<1
#define rs p<<1|1
using namespace std;
const int maxn = 2e5+30;
int n,m;
int p[maxn];
struct event{
    int l,r,w;
    bool operator < (const event &y) const{
        return r < y.r;
    }
}e[maxn];
int f[maxn];
int val[maxn<<2],tag[maxn<<2];
inline void pushup(int p) {
    val[p] = max(val[ls],val[rs]);
}
inline void pushdown(int p) {
    val[ls] += tag[p];
    val[rs] += tag[p];
    tag[ls] += tag[p];
    tag[rs] += tag[p];
    tag[p] = 0;
}
inline void modify(int p,int s,int e,int v,int l,int r) {
    if (s <= l && r <= e) {
        val[p] += v;
        tag[p] += v;
        return;
    }
    int mid = (l + r) >> 1;
    if (l != r && tag[p]) pushdown(p);
    if (s <= mid) modify(ls,s,e,v,l,mid);
    if (e > mid) modify(rs,s,e,v,mid+1,r);
    pushup(p);
}
signed main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= m; i++) cin >> e[i].l >> e[i].r >> e[i].w;
    sort(e+1,e+m+1);
    memset(f,0xc0,sizeof(f));
    f[0] = 0;
    int now = 1;
    for (int i = 1; i <= n; i++) {
        while (now <= m && e[now].r <= i) {
            modify(1,0,e[now].l-1,e[now].w,0,n);
            ++now;
        }
        modify(1,0,i-1,-p[i],0,n);
        f[i] = max(f[i-1],val[1]);
        modify(1,i,i,f[i],0,n);
    }
    cout << f[n] << '\n';
    return 0;
}