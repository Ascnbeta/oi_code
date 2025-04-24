#include <bits/stdc++.h>
#define ls p<<1
#define rs p<<1|1
using namespace std;
const int maxn = 1e6+40;
const int maxm = 1e7+30;
int n,m,p,q;
int val[maxn<<2],cnt[maxn<<2];
struct op{
    int l,r,c;
}opt[maxm];
inline void pushup(int p) {
    cnt[p] = cnt[ls] + cnt[rs];
}
inline void modify(int p,int s,int e,int v,int l,int r) {
    if (cnt[p] == r-l+1) return;
    if (l == r) {
        val[p] = v;
        cnt[p] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    if (s <= mid) modify(ls,s,e,v,l,mid);
    if (e > mid) modify(rs,s,e,v,mid+1,r);
    pushup(p);
}
inline void print(int p,int l,int r) {
    if (l == r) {
        cout << val[p] << '\n';
        return;
    }
    int mid = (l + r) >> 1;
    print(ls,l,mid);
    print(rs,mid+1,r);
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> m >> p >> q;
    for (int i = 1; i <= m; i++) {
        opt[i].l = (i*p+q)%n+1;
        opt[i].r = (i*q+p)%n+1;
        opt[i].c = i;
    }
    for (int i = m; i >= 1; i--) {
        if (opt[i].l > opt[i].r) swap(opt[i].r,opt[i].l);
        modify(1,opt[i].l,opt[i].r,opt[i].c,1,n);
    }
    print(1,1,n);
    return 0;
}