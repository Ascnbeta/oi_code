#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int t[400005],lz[400005];
int a[100005];
inline void pushup(int p) {
    t[p] = t[p*2] + t[p*2+1];
}
inline void pushdown(int p) {
    lz[p*2] += lz[p];
    lz[p*2+1] += lz[p];
    lz[p] = 0;
}
void build (int p,int l,int r) {
    if (l == r) {
        t[p] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    pushup(p);
}
int query(int l,int r,int s,int e,int p) {
    if (l <= s && r >= e) {
        return t[p];
    }
    int mid = (s + e) / 2,sum = 0;
    if (lz[p]) {
        t[p*2] += (mid - s + 1) * lz[p];
        t[p*2+1] += (e - mid) * lz[p];
        pushdown(p);
    }
    if (l <= mid) sum += query(l,r,s,mid,p*2);
    if (r > mid) sum += query(l,r,mid+1,e,p*2+1);
    return sum;
}
void modify_zone(int l,int r,int s,int e,int v,int p) {
    if (l <= s && r >= e) {
        t[p] += (e - s + 1) * v;
        lz[p] += v;
        return;
    }
    int mid = (s + e) / 2;
    if (lz[p] && s != e) {
        t[p*2] += (mid - s + 1) * lz[p];
        t[p*2+1] += (e - mid) * lz[p];
        pushdown(p);
    }
    if (l <= mid) modify_zone(l,r,s,mid,v,p*2);
    if (r > mid) modify_zone(l,r,mid+1,e,v,p*2+1);
    pushup(p);
}
signed main () {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1,1,n);
    while(m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x,y,z;
            cin >> x >> y >> z;
            modify_zone(x,y,1,n,z,1);
        }else{
            int x,y;
            cin >> x >> y;
            cout << query(x,y,1,n,1) << '\n';
        }
    }
    return 0;
}