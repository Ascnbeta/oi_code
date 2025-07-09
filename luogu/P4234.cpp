#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e4+5;
const int maxm = 2e5+5;
int n,m;
struct edge{
    int u,v,w;
    bool operator < (const edge &y) const{
        return w < y.w;
    }
}e[maxm];
struct zone{
    int l,r,time;
}z[maxm];
struct opt{
    int x,y,del;
}st[maxn<<1];int top;
#define ls p<<1
#define rs p<<1|1
vector<int> t[maxm<<2];
int father[maxn],rk[maxn];
inline int find(int x) {
    while (x != father[x]) x = father[x];
    return x;
}
inline void merge(int x,int y) {
    int p = find(x),q = find(y);
    if (rk[p] > rk[q]) swap(p,q);
    st[++top] = {p,q,rk[p]==rk[q]};
    father[p] = q;
    rk[q] += (rk[p] == rk[q]);
}
inline void modify(int p,int s,int e,int v,int l,int r) {
    if (s <= l && r <= e) return t[p].push_back(v),void();
    int mid = (l + r) >> 1;
    if (s <= mid) modify(ls,s,e,v,l,mid);
    if (e > mid) modify(rs,s,e,v,mid+1,r);
}
bool flag = false;
inline void solve(int p,int l,int r) {
    int lasttop = top;
    for (auto i : t[p]) {
        int x = find(e[i].u),y = find(e[i].v);
        if (x != y) {
            merge(x,y);
        }
    }
    if (l == r) {
        if (top == n-1) {
            flag = true;
        }
    }else{
        int mid = (l + r) >> 1;
        solve(ls,l,mid);
        solve(rs,mid+1,r);
    }
    while (top != lasttop) {
        father[st[top].x] = st[top].x; 
        rk[st[top].y] -= st[top].del;
        --top;
    }
    t[p].clear(),t[p].shrink_to_fit();
}  
inline bool check(int x) {
    int l=1,r=0,now=1,maxlen=0;
    while (l <= m) {
        while (r < m && e[r+1].w - e[l].w <= x) ++r,z[r].l=now;
        z[l].r = now;
        ++now;
        maxlen = max(z[l].r-z[l].l+1,maxlen);
        ++l;
    }
    if (maxlen < n-1) return false;
    for (int i = 1; i <= m; i++) {
        modify(1,z[i].l,z[i].r,i,1,m);
    }
    for (int i = 1; i <= n; i++) father[i] = i,rk[i] = 0;
    flag = false;
    solve(1,1,m);
    return flag;
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) cin >> e[i].u >> e[i].v >> e[i].w;
    sort(e+1,e+m+1);
    int l = 0,r = 10000,ans = 10000;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    cout << ans << '\n';
    return 0;
}