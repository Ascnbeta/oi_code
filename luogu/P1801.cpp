#include <bits/stdc++.h>
#define ls p<<1
#define rs p<<1|1
using namespace std;
const int maxn = 2e5+30;
int a[maxn],b[maxn],u[maxn];
int n,m;
int f[maxn];
int sum[maxn<<2];
inline void pushup(int p) {
    sum[p] = sum[ls] + sum[rs];
}
inline void modify(int p,int pos,int v,int l,int r) {
    if (l == r) {
        sum[p]++;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) modify(ls,pos,v,l,mid);
    else modify(rs,pos,v,mid+1,r);
    pushup(p);
}
inline int query(int p,int k,int l,int r) {
    if (l == r) return l;
    int mid = (l + r) >> 1;
    if (k <= sum[ls]) return query(ls,k,l,mid);
    else return query(rs,k-sum[ls],mid+1,r);
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i],b[i] = a[i];
    for (int i = 1; i <= m; i++) cin >> u[i],f[u[i]]++;
    int cur = 0;
    sort(b+1,b+n+1);
    int n1 = unique(b+1,b+n+1)-b-1;
    for (int i = 1; i <= n; i++) a[i] = lower_bound(b+1,b+n1+1,a[i])-b;
    for (int i = 1; i <= n; i++) {
        modify(1,a[i],1,1,n1);
        while (f[i]) {
            ++cur;
            cout << b[query(1,cur,1,n1)] << '\n';
            --f[i];
        }
    }
    return 0;
}