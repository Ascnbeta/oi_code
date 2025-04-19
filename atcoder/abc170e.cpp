#include <bits/stdc++.h>
using namespace std;
const int maxn = 9e6+30;
const int n = 2e5;
int N,q,min1 = 0x3f3f3f3f,min2 = 0x3f3f3f3f;
int val[maxn],ls[maxn],rs[maxn],rt[200005],tot;
int f[200004];
inline void pushup(int p) {
    val[p] = max(val[ls[p]],val[rs[p]]);
}
inline void modify (int &p,int pos,int v,int l,int r) {
    if (!p) p = ++tot;
    if (l == r) {
        val[p] = v;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) modify(ls[p],pos,v,l,mid);
    else modify(rs[p],pos,v,mid+1,r);
    pushup(p);
}
int t[800004],a[200005];
inline void build(int p,int l,int r) {
    if (l == r) {
        if (val[rt[l]] == 0) t[p] = 0x3f3f3f3f;
        else t[p] = val[rt[l]];
        return;
    }
    int mid = (l + r) >> 1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    t[p] = min(t[p<<1],t[p<<1|1]);
}
inline void change (int p,int pos,int v,int l,int r) {
    if (l == r) {
        if (v == 0) t[p] = 0x3f3f3f3f;
        else t[p] = v;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) change(p<<1,pos,v,l,mid);
    else change(p<<1|1,pos,v,mid+1,r);
    t[p] = min(t[p<<1],t[p<<1|1]);
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> N >> q;
    for (int i = 1; i <= n; i++) rt[i] = ++tot;
    for (int i = 1; i <= N; i++) {
        int b;
        cin >> a[i] >> b;
        modify(rt[b],i,a[i],1,n);
        f[i] = b;
    }
    build(1,1,n);
    // cout << t[1] << '\n';
    for (int i = 1; i <= q; i++) {
        int c,d;
        cin >> c >> d;
        modify(rt[f[c]],c,0,1,n);
        // cout << val[rt[f[c]]] << "awa\n";
        change(1,f[c],val[rt[f[c]]],1,n);
        
        f[c] = d;
        modify(rt[d],c,a[c],1,n);
        change(1,d,val[rt[d]],1,n);
        cout << t[1] << '\n';
    }
    return 0;
}