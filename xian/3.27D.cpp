#include <bits/stdc++.h>
#define ls p<<1
#define rs p<<1|1
#define int long long
using namespace std;
const int maxn = 1e5+30;
int n,a,cf,cm,m,minn = INT_MAX,ans;
int g[maxn],sum[maxn],sum2[maxn];
struct node{
    int min,sum,tag;
}t[maxn<<2];
inline void pushup(int p) {
    t[p].min = min(t[ls].min,t[rs].min);
    t[p].sum = t[ls].sum + t[rs].sum;
}
inline void pushdown(int p,int l,int r) {
    int mid = (l + r) >> 1;
    if (t[p].tag == 0) {
        t[ls].min = g[mid];
        t[ls].sum = sum2[mid] - sum2[l-1];
        t[rs].min = g[r];
        t[rs].sum = sum2[r] - sum2[mid];
        t[ls].tag = t[rs].tag = 0;
        t[p].tag = -1;
    }else{
        t[ls].min = t[rs].min = t[p].tag;
        t[ls].sum = t[p].tag * (mid-l+1);
        t[rs].sum = t[p].tag * (r-mid);
        t[ls].tag = t[rs].tag = t[p].tag;
        t[p].tag = -1;
    }
}
inline void build(int p,int l,int r) {
    t[p].tag = -1;
    if (l == r) {
        t[p].min = t[p].sum = g[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(p);
}
inline void modify(int p,int v,int s,int e,int l,int r) {
    if (s > e) return;
    if (s <= l && r <= e){
        if (v == 0) {
            t[p].sum = sum2[r]-sum2[l-1];
            t[p].min = g[r];
            t[p].tag = 0;
        }else{
            t[p].sum = (r-l+1)*v;
            t[p].min = v;
            t[p].tag = v;
        }
        return;
    }
    int mid = (l + r) >> 1;
    if (l != r && t[p].tag != -1) pushdown(p,l,r);
    if (s <= mid) modify(ls,v,s,e,l,mid);
    if (e > mid) modify(rs,v,s,e,mid+1,r);
    pushup(p);
}
inline int query(int p,int v,int l,int r) {
    if (l != r && t[p].tag != -1) pushdown(p,l,r);
    if (l == r) {
        if (v >= t[p].sum) return v-t[p].sum;
        else return 0;
    }
    int mid = (l + r) >> 1;
    if (t[ls].min >= v) {
        return query(rs,v,mid+1,r);
    }else{
        return query(ls,v,l,mid) + v*(r-mid)-t[rs].sum;
    }
}
inline int calc(int x) {
    if (sum[x] > m) return 0;
    int lft = m - sum[x];
    int l = minn,r = a,ret = minn;
    modify(1,a,1,x,1,n);
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (query(1,mid,1,n) <= lft) {
            ret = mid;
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    modify(1,0,1,x,1,n);
    //cout << x << ' ' << query(1,ret,1,n) << ' ' << ret << ' ' << x*cf+ret*cm << '\n';
    return x*cf+ret*cm;
}

signed main() {
#ifdef LOCAL
    freopen("E:/codes/exe/a.in","r",stdin);
    freopen("E:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> a >> cf >> cm >> m;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> g[i];
        
        minn = min(minn,g[i]);
        if (g[i] == a) ++cnt;
    }
    sort(g+1,g+n+1,greater<int>());
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i-1]+a-g[i];
        sum2[i] = sum2[i-1] + g[i];
    }
    build(1,1,n);
    ans = cnt * cf + minn * cm;
    for (int i = 0; i <= n; i++) {
        ans = max(ans,calc(i));
    }
    cout << ans << '\n';
    return 0;
}