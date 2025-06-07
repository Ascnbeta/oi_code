#include <bits/stdc++.h>
#define fi first
#define se second
typedef long long ll;
using namespace std;
inline void read(int &x) {
    x=0;int f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {
        if (ch=='-') f=-1;
        ch=getchar();
    }
    while (ch>='0'&&ch<='9') {
        x=(x<<3)+(x<<1)+(ch^48);
        ch=getchar();
    }
    x*=f;
}
const int maxn = 3e5+30;
int n,m;
vector<pair<int,int>> e[maxn];
int dfn[maxn],siz[maxn],dis[maxn],dep[maxn],son[maxn],top[maxn],f[maxn],cnt;
void dfs1(int u,int fa) {
    siz[u]=1;
    dep[u]=dep[fa]+1;
    for (auto i : e[u]) {
        int v=i.fi,w=i.se;
        if (v == fa) continue;
        dis[v]=dis[u]+w;
        f[v]=u;
        dfs1(v,u);
        siz[u]+=siz[v];
        if (siz[v]>siz[son[u]]) son[u]=v;
    }
}
void dfs2(int u,int fa,int p) {
    top[u]=p;
    dfn[u]=++cnt;
    if (son[u]) dfs2(son[u],u,p);
    for (auto i : e[u]) {
        int v=i.fi;
        if (v==son[u]||v==fa) continue;
        dfs2(v,u,v);
    }
}
inline int get_lca(int u,int v) {\
    while (top[u] != top[v]) {
        if (dep[top[u]] > dep[top[v]]) {
            u = f[top[u]];
        }else{
            v = f[top[v]];
        }
    }
    return dep[u]>dep[v]?v:u;
}
int st[maxn],ed[maxn],lca[maxn],sum[maxn];
int c[maxn],s[maxn],maxx,cntm,mid;
bool dfs3(int u,int fa,int w) {
    s[u] = c[u];
    bool flag = false;
    for (auto i : e[u]) {
        int v = i.fi;
        if (v == fa) continue;
        flag |= dfs3(v,u,i.se);
        s[u] += s[v]; 
    } 
    if (s[u] == cntm && maxx - w <= mid) flag |= true;
    return flag;
}
inline bool check() {
    memset(c,0,sizeof(c));
    memset(s,0,sizeof(s));
    maxx = cntm = 0;
    for (int i = 1; i <= m; i++) {
        if (sum[i] > mid) {
            c[st[i]]+=1;
            c[ed[i]]+=1;
            c[lca[i]]-=2;
            maxx = max(sum[i],maxx);
            ++cntm;
        }
    }
    return dfs3(1,0,0);
}
int maxv,maxw;
int main () {
#ifdef LOCAL
    freopen("D:\\codes\\exe\\a.in","r",stdin);
    freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
    read(n),read(m);
    for (int i = 1; i < n; i++) {
        int u,v,w;
        read(u),read(v),read(w);
        e[u].push_back({v,w});
        e[v].push_back({u,w});
        maxw=max(w,maxw);
    }
    dfs1(1,0);
    dfs2(1,0,1);
    for (int i = 1; i <= m; i++) {
        read(st[i]),read(ed[i]);
        lca[i] = get_lca(st[i],ed[i]);
        sum[i] = (long long)dis[st[i]]+dis[ed[i]]-2ll*dis[lca[i]];
        maxv = max(maxv,sum[i]);
    }
    int l = maxv-maxw,r = maxv,ans = maxv;
    while (l <= r) {
        mid = (l+r)>>1;
        if (check()) {
            ans = mid;
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    printf("%d",ans);
    return 0;
}