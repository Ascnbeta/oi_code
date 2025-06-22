#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template <typename T>
inline void read(T &x) {
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
const int maxn = 1e5+30;
const int maxm = 2e5+40;
int T;
int n,m,K;ll mod;
vector<pair<int,ll>> e[maxm],e1[maxm];
ll dis[maxn];
struct node{
    int p;ll w;
    bool operator < (const node &y) const {
        return w > y.w;
    }
};
priority_queue<node> q;
bool vis[maxn];
inline void dijkstra() {
    dis[1] = 0;
    q.push({1,0});
    while (!q.empty()) {
        node t = q.top();
        q.pop();
        if (vis[t.p]) continue;
        vis[t.p] = true;
        for (auto i : e[t.p]) {
            int v = i.first;ll w = i.second;
            if (dis[v] > dis[t.p] + w) {
                dis[v] = dis[t.p] + w;
                q.push({v,dis[v]});
            }
        }
    }
}
ll f[maxn][52];bool g[maxn][52],flag;
ll dfs(int u,int k) {
    if (g[u][k]) {
        flag = true;
        return 0;
    }
    if (~f[u][k]) return f[u][k];
    g[u][k] = true;
    f[u][k] = 0;
    for (auto i : e1[u]) {
        int v = i.first;ll w = i.second;
        int tmp = k+dis[u]-w-dis[v];
        if (tmp < 0 || tmp > K) continue;
        f[u][k] = (f[u][k]+dfs(v,tmp))%mod;
        if (flag) return g[u][k]=false,0;
    }
    if(u == 1 && k == 0) f[u][k] = 1;
    g[u][k] = false;
    return f[u][k];
}
int main() {
#ifdef LOCAL
    freopen("E:/OI/exe/a.in","r",stdin);
    freopen("E:/OI/exe/a.out","w",stdout);
#endif
    read(T);
    while (T--) {
        read(n),read(m),read(K),read(mod);
        for (int i = 1; i <= n; i++) e[i].clear(),e1[i].clear(),vis[i] = 0,dis[i] = 0x3f3f3f3f3f3f3f3f;
        memset(f,-1,sizeof(f));
        flag = false;
        for (int i = 1; i <= m; i++) {
            int u,v,w;
            read(u),read(v),read(w);
            e[u].push_back({v,1ll*w});
            e1[v].push_back({u,1ll*w});
        }
        dijkstra();
        ll ans = 0;
        for (int i = 0; i <= K; i++) {
            ans = (ans+dfs(n,i))%mod;
            if (flag) {
                ans = -1;break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}