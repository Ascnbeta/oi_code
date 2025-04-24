#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+30;
int n,q;
struct edge{
    int u,v,w;
    bool operator < (const edge &y) const{
        return w > y.w;
    }
}e[maxn];
struct ask{
    int k,v,ans,id;
}a[maxn];
bool cmp1 (const ask x,const ask y) {
    return x.k > y.k;
}
bool cmp2 (const ask x,const ask y) {
    return x.id < y.id;
}
int fa[maxn],rk[maxn],siz[maxn];
inline int find(int x) {
    int t = x;
    while (x != fa[x]) x = fa[x];
    int w;
    while (t != fa[t]) w = fa[t],fa[t] = x,t = w;
    return x;
}
inline void merge(int x,int y) {
    int p = find(x),q = find(y);
    if (p == q) return;
    if (rk[p] < rk[q]) {
        fa[p] = q;
        rk[q] = max(rk[q],rk[p]+1);
        siz[q] += siz[p];
    }else{
        fa[q] = p;
        rk[p] = max(rk[p],rk[q]+1);
        siz[p] += siz[q];
    }
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> q;
    for (int i = 1; i <= n; i++) fa[i] = i,siz[i] = rk[i] = 1;
    for (int i = 1; i < n; i++) {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    sort(e+1,e+n);
    for (int i = 1; i <= q; i++) {
        cin >> a[i].k >> a[i].v;
        a[i].id = i;
    }
    sort(a+1,a+q+1,cmp1);
    if (n == 1) {
        cout << 0 << '\n';
        return 0;
    }
    int now = 1;
    for (int i = 1; i <= q; i++) {
        while (e[now].w >= a[i].k && now < n) {
            merge(e[now].u,e[now].v);
            ++now;
        }
        a[i].ans = siz[find(a[i].v)];
    }
    sort(a+1,a+q+1,cmp2);
    for (int i = 1; i <= q; i++) {
        cout << a[i].ans-1 << '\n';
    }
    return 0;
}