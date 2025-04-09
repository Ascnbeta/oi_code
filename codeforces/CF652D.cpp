#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e5+30;
int n;
struct line{
    int l,r,id,ans;
}l[maxn];
bool cmp1 (const line x,const line y) {
    return x.r < y.r;
}
bool cmp2 (const line x,const line y) {
    return x.id < y.id;
}
int b[maxn<<1];
int t[maxn<<1];
inline int lowbit(int x) {
    return x&(-x);
}
inline void modify(int p,int x) {
    while (p <= 2*n) {
        t[p] += x;
        p += lowbit(p);
    }
}
inline int query(int p) {
    int ret = 0;
    while (p > 0) {
        ret += t[p];
        p -= lowbit(p);
    }
    return ret;
}
signed main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> l[i].l >> l[i].r;
        l[i].id = i;
        b[i] = l[i].l,b[i+n] = l[i].r;
    }
    sort(b+1,b+2*n+1);
    for (int i = 1; i <= n; i++) {
        l[i].l = lower_bound(b+1,b+2*n+1,l[i].l)-b;
        l[i].r = lower_bound(b+1,b+2*n+1,l[i].r)-b;
    }
    sort(l+1,l+n+1,cmp1);
    for (int i = 1; i <= n; i++) {
        l[i].ans = query(l[i].r)-query(l[i].l-1);
        modify(l[i].l,1);
    }
    sort(l+1,l+n+1,cmp2);
    for (int i = 1; i <= n; i++) cout << l[i].ans << '\n';
    return 0;
}