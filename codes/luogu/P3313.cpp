#include <bits/stdc++.h>
#define size siz
using namespace std;
const int maxn = 1e5+10;
int n,q;
int w[maxn],c[maxn];
vector<int> e[maxn];
int dfn[maxn],top[maxn],son[maxn],size[maxn],f[maxn],dep[maxn],rnk[maxn],cnt;
void dfs1(int u,int fa) {
    size[u] = 1;
    son[u] = 0;
    dep[u] = dep[fa] + 1;
    for (auto &v : e[u]) {
        if (v == fa) continue;
        f[v] = u;
        dfs1(v,u);
        size[u] += size[v];
        if (size[v] > size[son[u]]) son[u] = v;
    }
}
void dfs2(int u,int fa,int tp) {
    top[u] = tp;
    dfn[u] = ++cnt;
    rnk[cnt] = u;
    if (son[u] == 0) return;
    dfs2(son[u],u,tp);
    for (auto &v : e[u]) {
        if (v == fa || v == son[u]) continue;
        dfs2(v,u,v); 
    }
}
struct node{
    int sum,max;
}t[3600000];
int rt[maxn],ls[3600000],rs[3600000];
inline void pushup(int p) {
    t[p].sum = t[ls[p]].sum + t[rs[p]].sum;
    t[p].max = max(t[ls[p]].max,t[rs[p]].max);
}
void modify(int &p,int v,int pos,int s,int e) {
    if (!p) p = ++cnt;
    if (s == e) {
        t[p].sum = t[p].max = v;
        return;
    }
    int mid = (s + e) >> 1;
    if (pos <= mid) modify(ls[p],v,pos,s,mid);
    else modify(rs[p],v,pos,mid+1,e);
    pushup(p);
}
int querymax(int p,int l,int r,int s,int e) {
    if (!p) return 0;
    if (l <= s && e <= r) {
        return t[p].max;
    }
    int mid = (s + e) >> 1;
    int ret = 0;
    if (l <= mid) ret = max(ret,querymax(ls[p],l,r,s,mid));
    if (r > mid) ret = max(ret,querymax(rs[p],l,r,mid+1,e));
    return ret;
}
int querysum(int p,int l,int r,int s,int e) {

    if (!p) return 0;
    if (l <= s && e <= r) {
        return t[p].sum;
    }
    int mid = (s + e) >> 1;
    int ret = 0;
    if (l <= mid) ret += querysum(ls[p],l,r,s,mid);
    if (r > mid) ret += querysum(rs[p],l,r,mid+1,e);
    return ret;
}
int querysum_path(int x,int y) {
    int ret = 0,fx = top[x],fy = top[y];
    int color = c[x];
    while (fx != fy) {
        if (dep[fx] >= dep[fy]) {
            ret += querysum(rt[color],dfn[fx],dfn[x],1,n);
            x = f[fx];
        }else{
            ret += querysum(rt[color],dfn[fy],dfn[y],1,n);
            y = f[fy];
        }
        fx = top[x],fy = top[y];
    }
    if (dep[x] >= dep[y]) {
        ret += querysum(rt[color],dfn[y],dfn[x],1,n);
    }else{
        ret += querysum(rt[color],dfn[x],dfn[y],1,n);
    }
    return ret;
}
int querymax_path(int x,int y) {
    int ret = 0,fx = top[x],fy = top[y];
    int color = c[x];
    while (fx != fy) {
        if (dep[fx] >= dep[fy]) {
            ret = max(ret,querymax(rt[color],dfn[fx],dfn[x],1,n));
            x = f[fx];
        }else{
            ret = max(ret,querymax(rt[color],dfn[fy],dfn[y],1,n));
            y = f[fy];
        }
        fx = top[x],fy = top[y];
    }
    if (dep[x] >= dep[y]) {
        ret = max(ret,querymax(rt[color],dfn[y],dfn[x],1,n));
    }else{
        ret = max(ret,querymax(rt[color],dfn[x],dfn[y],1,n));
    }
    return ret;
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
#ifdef LOCAL
    freopen("D:\\codes\\exe\\a.in","r",stdin);
    freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> w[i] >> c[i];
    for (int i = 1; i < n; i++) {
        int u,v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs1(1,0);
    dfs2(1,0,1);
    cnt = 0;
    for (int i = 1; i <= n; i++) {
        modify(rt[c[i]],w[i],dfn[i],1,n);
    }
    // cout << dfn[4] << '\n';
    while (q--) {
        string opt;
        int x,y;
        cin >> opt >> x >> y;
        if (opt == "CC") {
            modify(rt[c[x]],0,dfn[x],1,n);
            modify(rt[y],w[x],dfn[x],1,n);
            c[x] = y;
        }
        if (opt == "CW") {
            modify(rt[c[x]],y,dfn[x],1,n);
            w[x] = y;
        }
        if (opt == "QS") {
            cout << querysum_path(x,y) << '\n';
        }
        if (opt == "QM") {
            cout << querymax_path(x,y) << '\n';
        }
    }
    return 0;
}