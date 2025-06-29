#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
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
int n;ll mod;
vector<int> e[maxn];
ll f[maxn],g[maxn],son[maxn];
vector<ll> pre[maxn],suf[maxn];
void dfs1(int u,int fa) {
    f[u] = 1;
    for (int i = 0; i < e[u].size(); i++) {
        int v = e[u][i];
        if (v == fa) {
            pre[u].push_back(1);suf[u].push_back(1);continue;
        }
        ++son[u];
        dfs1(v,u);
        pre[u].push_back((f[v]+1)%mod);
        suf[u].push_back((f[v]+1)%mod);
        f[u] = f[u]*(f[v]+1)%mod;
    }
    for (int i = 1; i < pre[u].size(); i++) pre[u][i] = pre[u][i-1]*pre[u][i]%mod;
    for (int i = (int)suf[u].size()-2; i >= 0; i--) suf[u][i] = suf[u][i]*suf[u][i+1]%mod;
}
void dfs2(int u,int fa) {
    for (int i = 0; i < e[u].size(); i++) {
        int v = e[u][i];
        if (v == fa) continue;
        if (son[u]==1) g[v]=g[u]+1;
        else if (i == 0) g[v]=g[u]*suf[u][i+1]%mod+1;
        else if (i == (int)e[u].size()-1) g[v]=g[u]*pre[u][i-1]%mod+1;
        else g[v]=g[u]*pre[u][i-1]%mod*suf[u][i+1]%mod+1;
        dfs2(v,u);
    }
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(n),read(mod);
    for (int i = 1; i < n; i++) {
        int u,v;
        read(u),read(v);
        e[u].push_back(v),e[v].push_back(u);
    }
    dfs1(1,0);
    g[1] = 1;
    dfs2(1,0);
    for (int i = 1; i <= n; i++) printf("%lld\n",f[i]*g[i]%mod);
    return 0;
}