#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 571343;
int n,q,m;
int a[100004];
int t[400004],lz_t[400004],lz_p[400004];
inline void pushup(int p) {
    t[p] = (t[p<<1] + t[p<<1|1]) % mod;
}
inline void pushdown(int p) {
    lz_t[p<<1|1] = lz_t[p<<1|1] * lz_t[p] % mod;
    lz_t[p<<1] = lz_t[p<<1] * lz_t[p] % mod;
    lz_p[p<<1] = (lz_p[p<<1] * lz_t[p] + lz_p[p]) % mod;
    lz_p[p<<1|1] = (lz_p[p<<1|1] * lz_t[p] + lz_p[p]) % mod;  
    lz_p[p] = 0;
    lz_t[p] = 1;
}
void build(int p,int l,int r) {
    if (l == r) {
        t[p] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    pushup(p);
}
void modify_t(int l,int r,int v,int s,int e,int p) {
    if (l <= s && e <= r) {
        t[p] = t[p] * v % mod;
        lz_p[p] = lz_p[p] * v % mod;
        lz_t[p] = lz_t[p] * v % mod;
        return;
    }
    int mid = (s + e) >> 1;
    if ((lz_t[p] != 1|| lz_p[p]) && s != e) {
        t[p<<1] = t[p<<1] * lz_t[p] % mod;
        t[p<<1|1] = t[p<<1|1] * lz_t[p] % mod;
        t[p<<1] = (t[p<<1] + lz_p[p]*(mid-s+1)) % mod;
        t[p<<1|1] = (t[p<<1|1] + lz_p[p]*(e-mid)) % mod;
        pushdown(p);
    }
    if (l <= mid) modify_t(l,r,v,s,mid,p<<1);
    if (r > mid) modify_t(l,r,v,mid+1,e,p<<1|1);
    pushup(p);
}
void modify_p(int l,int r,int v,int s,int e,int p) {
    if (l <= s && e <= r) {
        t[p] = (t[p] + v*(e-s+1)) % mod;
        lz_p[p] = (lz_p[p] + v) % mod;
        return;
    }
    int mid = (s + e) >> 1;
    if ((lz_t[p] != 1|| lz_p[p]) && s != e) {
        t[p<<1] = t[p<<1] * lz_t[p] % mod;
        t[p<<1|1] = t[p<<1|1] * lz_t[p] % mod;
        t[p<<1] = (t[p<<1] + lz_p[p]*(mid-s+1)) % mod;
        t[p<<1|1] = (t[p<<1|1] + lz_p[p]*(e-mid)) % mod;
        pushdown(p);
    }
    if (l <= mid) modify_p(l,r,v,s,mid,p<<1);
    if (r > mid) modify_p(l,r,v,mid+1,e,p<<1|1);
    pushup(p);
}
int query(int l,int r,int s,int e,int p) {
    if (l <= s && e <= r) return t[p];
    int mid = (s + e) >> 1;
    int sum = 0;
    if ((lz_t[p] != 1 || lz_p[p]) && s != e) {
        t[p<<1] = t[p<<1] * lz_t[p] % mod;
        t[p<<1|1] = t[p<<1|1] * lz_t[p] % mod;
        t[p<<1] += lz_p[p]*(mid-s+1) % mod;
        t[p<<1|1] += lz_p[p]*(e-mid) % mod;
        pushdown(p);
    }
    if (l <= mid) sum += query(l,r,s,mid,p<<1) % mod;
    if (r > mid) sum += query(l,r,mid+1,e,p<<1|1) % mod;
    return sum % mod;
}
signed main () {
    cin >> n >> q >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    fill(lz_t+1,lz_t+400003,1);
    build(1,1,n);
    while (q--) {
        int op,x,y,z;
        cin >> op;
        if (op == 1) {
            cin >> x >> y >> z;
            modify_t(x,y,z,1,n,1);
        }
        if (op == 2) {
            cin >> x >> y >> z;
            modify_p(x,y,z,1,n,1);
        }
        if (op == 3) {
            cin >> x >> y;
            cout << query(x,y,1,n,1) % mod<< '\n';
        }
    }
    return 0;
}