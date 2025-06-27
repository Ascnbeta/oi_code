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
ll f[maxn],g[maxn];
vector<ll> prod[maxn];
void dfs1(int u,int fa) {
    f[u] = 1;
    prod[u].push_back(f[u]);
    for (int i = 0; i < e[u].size(); i++) {
        int v = e[u][i];
        if (v == fa) {
            prod[u].push_back(prod[u][i]*1%mod);continue;
        }
        dfs1(v,u);
        prod[u].push_back(prod[u][i]*(f[v]+1)%mod);
        f[u] = f[u]*(f[v]+1)%mod;
    }
}
void dfs2(int u,int fa) {
    for (int i = 0; i < e[u].size(); i++) {
        int v = e[u][i];
        if (v == fa) continue;
        g[v] = f[u]*
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
    g[1] = f[1];
    dfs2(1,0);
    return 0;
}