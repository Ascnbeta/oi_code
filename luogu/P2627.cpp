#include <bits/stdc++.h>
#define int long long
#define ls p<<1
#define rs p<<1|1
using namespace std;
const int maxn = 1e6+30;
int n,k,e[maxn],sum[maxn];
int f[maxn];
struct node{
    int max;
}t[maxn<<2];
inline void pushup(int p) {
    t[p].max = max(t[ls].max,t[rs].max);
}
inline void build(int p,int l,int r) {
    if (l == r) {
        t[p].max = -sum[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(p);
}
inline void modify(int p,int pos,int v,int l,int r){
    if (l == r) {
        t[p].max += v;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) modify(ls,pos,v,l,mid);
    else modify(rs,pos,v,mid+1,r);
    pushup(p);
}
inline int query(int p,int s,int e,int l,int r) {
    if (s <= l && r <= e) {
        return t[p].max;
    }
    int mid = (l + r) >> 1;
    int ret = 0xcfcfcfcfcfcfcfcf;
    if (s <= mid) ret = max(ret,query(ls,s,e,l,mid));
    if (e > mid) ret = max(ret,query(rs,s,e,mid+1,r));
    return ret;
}
signed main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> e[i],sum[i] = sum[i-1] + e[i];
    build(1,1,n);
    for (int i = 1; i <= min(k,n); i++) {
        f[i] = sum[i];
        modify(1,i+1,f[i],1,n);
    }
    for (int i = k+1; i <= n; i++) {
        f[i] = max(f[i-1],sum[i]+query(1,max(1ll,i-k),i-1,1,n));
        modify(1,i+1,f[i],1,n);
    }
    // for (int i = 1; i <= n; i++) cout << f[i] << ' ';
    // cout << '\n';
    cout << f[n] << '\n';
    return 0;
}