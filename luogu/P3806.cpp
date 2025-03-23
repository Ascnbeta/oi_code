#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+30;
int n,m;
int query[103],ans[103],path[10000032];
struct edge{
    int to,nxt,w;
}e[maxn<<1];
int head[maxn],tot;
int siz[maxn],maxd[maxn],dis[maxn],rem[maxn],tmp[maxn],rt,sum;
bool vis[maxn];
inline void add(int u,int v,int w) {
    e[++tot].to = v;
    e[tot].w = w;
    e[tot].nxt = head[u];
    head[u] = tot;
}
inline void getrt(int u,int fa) {
    siz[u] = 1,maxd[u] = 0;
    for (int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if (v == fa || vis[v]) continue;
        getrt(v,u);
        siz[u] += siz[v];
        maxd[u] = max(maxd[u],siz[v]); 
    }
    maxd[u] = max(maxd[u],sum-siz[u]);
    if (!rt || maxd[u] < maxd[rt]) rt = u;
}
inline void getdis(int u,int fa) {
    rem[++rem[0]] = dis[u];
    for (int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].to,w = e[i].w;
        if (vis[v] || v == fa) continue;
        dis[v] = dis[u] + w;
        getdis(v,u);
    }
}
inline void calc(int u) {
    int tot = 0;
    for (int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].to,w = e[i].w;
        if (vis[v]) continue;
        rem[0] = 0;//计数变量，统计共有多少个路径。
        dis[v] = w;
        getdis(v,u);
        for (int j = rem[0]; j >= 1; j--) {
            for (int k = 1; k <= m; k++) {
                if (query[k] >= rem[j]) {
                    ans[k] |= path[query[k]-rem[j]];
                }
            }
        }
        for (int j = rem[0]; j >= 1; j--) {
            if (rem[j] > 10000000) continue;
            tmp[++tot] = rem[j],path[rem[j]] = 1;
        }
    }
    for (int i = 1; i <= tot; i++) path[tmp[i]] = 0;
}
inline void solve(int u) {
    vis[u] = true;path[0] = 1;calc(u);
    for (int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if (vis[v]) continue;
        rt = 0,sum = siz[v];
        getrt(v,0); solve(rt);
    }
}
int main() {  
#ifdef LOCAL
    freopen("E:/codes/exe/a.in","r",stdin);
    freopen("E:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        add(u,v,w);
        add(v,u,w);
    }
    for (int i = 1;i <= m; i++) {
        cin >> query[i];
        if (query[i] == 0) ans[i] = 1;
    }
    rt = 0;
    sum = n;
    getrt(1,0);
    solve(rt);
    for (int i = 1; i <= m; i++) {
        if (ans[i] == 1) {
            puts("AYE");
        }else{
            puts("NAY");
        }
    }
    return 0;
}