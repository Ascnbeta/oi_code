#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
inline void read(int &x) {
    x=0;int f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){
        if (ch=='-') f=-1;
        ch=getchar();
    }
    while (ch>='0'&&ch<='9') {
        x=(x<<3)+(x<<1)+(ch^48);
        ch=getchar();
    }
    x*=f;
}
const int maxn = 2e5+30;
const int maxm = 2e5+30;
int T,n,m;
struct edge{
    int to,nxt,w;
}e[maxm<<1];
int head[maxn],tot;
int head1[maxn];
inline void add(int u,int v,int w) {
    e[++tot].to = v;
    e[tot].nxt = head[u];
    e[tot].w = w;
    head[u] = tot;
}
int dfn[maxn],low[maxn],cnt;
int scc[maxn],sc;
int st[maxn],top;bool instk[maxn];
void tarjan(int u) {
    dfn[u]=low[u]=++cnt;
    st[++top]=u;instk[u]=true;
    for (int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u],low[v]);
        }else if(instk[v]) {
            low[u] = min(low[u],dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        ++sc;
        while (top > 0) {
            int x = st[top--];
            instk[x] = false;
            scc[x] = sc;
            if (x == u) break;
        }
    }
}
int dg[maxn],cnt0;
inline bool check(ll x) {
    for (int i = 1; i <= n; i++) dg[i]=dfn[i]=0,head[i]=head1[i];
    cnt=sc=cnt0=0,tot=m;
    for (int i = 1; i <= n; i++) {
        for (int j = head1[i]; j; j = e[j].nxt) {
            int v = e[j].to;
            if (e[j].w > x) continue;
            add(v,i,e[j].w);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) tarjan(i);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = head[i]; j; j = e[j].nxt) {
            int v = e[j].to;
            if (scc[i]==scc[v]) continue;
            ++dg[scc[v]];
        }
    }
    for (int i = 1; i <= sc; i++) {
        if (dg[i] == 0) {
            ++cnt0;
            if (cnt0 > 1) return false;
        }
    }
    return true;
}
ll maxx = 0;
int main () {
#ifdef LOCAL
    freopen("D:\\codes\\exe\\a.in","r",stdin);
    freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
    read(T);
    while (T--) {
        read(n),read(m);
        tot = maxx = 0;for (int i = 1; i <= n; i++) head[i] = 0;
        for (int i = 1; i <= m; i++) {
            int u,v,w;
            read(u),read(v),read(w);
            maxx = max((long long)w,maxx);
            add(u,v,w);
        }
        for (int i = 1; i <= n; i++) head1[i] = head[i];
        ll l = 0,r = maxx+3,ans = maxx+3;
        while (l <= r) {
            ll mid = (l + r) >> 1;
            assert(mid>=0);
            if (check(mid)) {
                ans = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        if (ans <= maxx) printf("%lld\n",ans);
        else puts("-1");
    }
    return 0;
}