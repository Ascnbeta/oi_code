#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+40;
int n,m,maxx,ans[maxn];
struct board{
    int l,r,s;
}b[maxn];
vector<int> pos[maxn];
int sum[maxn<<5],ls[maxn<<5],rs[maxn<<5],rt[maxn],tot,cnt;
int idx[maxn];
inline void pushup(int p) {
    sum[p] = sum[ls[p]] + sum[rs[p]];
}
void build(int &p,int l,int r) {
    if (!p) p = ++tot;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(ls[p],l,mid);
    build(rs[p],mid+1,r);
    pushup(p);
}
inline int modify(int p,int pos,int l,int r) {
    int pt = ++tot;
    sum[pt] = sum[p],ls[pt] = ls[p],rs[pt] = rs[p];
    if (l == r) {
        sum[pt]++;
        return pt;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) {
        ls[pt] = modify(ls[p],pos,l,mid);
    }else{
        rs[pt] = modify(rs[p],pos,mid+1,r);
    }
    pushup(pt);
    return pt;
}
inline int query(int p1,int p2,int v,int l,int r) {
    if (sum[p2]-sum[p1] < v) return 0;
    if (l == r) {
        if (v == 1) return l;
        else return 0;
    }
    int mid = (l + r) >> 1;
    int tmp = sum[ls[p2]]-sum[ls[p1]];
    if (tmp >= v) return query(ls[p1],ls[p2],v,l,mid);
    else return query(rs[p1],rs[p2],v-tmp,mid+1,r);
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> b[i].l >> b[i].r >> b[i].s,maxx = max(maxx,b[i].r);
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        pos[x].push_back(i);
    }
    build(rt[0],1,m);
    for (int i = 1; i <= 200000; i++) {
        for (int j : pos[i]) {
            ++cnt;
            idx[cnt] = i;
            rt[cnt] = modify(rt[cnt-1],j,1,m);
        }
    }
    for (int i = 1; i <= n; i++) {
        int l = lower_bound(idx,idx+cnt+1,b[i].l)-idx-1;
        int r = lower_bound(idx,idx+cnt+1,b[i].r+1)-idx-1;
        // cout << l << ' ' << r << '\n';
        // cout << query(rt[l],rt[r],b[i].s,1,m) << '\n';
        ans[query(rt[l],rt[r],b[i].s,1,m)]++;
    }
    for (int i = 1; i <= m; i++) cout << ans[i] << '\n';
    return 0;
}