#include <bits/stdc++.h>
#define int long long
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
template <typename T>
inline void write(T x) {
    if (x<0) x=-x,putchar('-');
    if (x/10) write(x/10);
    putchar('0'+x%10);
}
const int maxn = 5e5+5;
int n,m;
ll w[maxn];
vector<int> e[maxn];
ll f[maxn][2],tmp[maxn];int deg[maxn];
ll val[maxn],tot;
void dfs(int u,int fa) {
    for (auto v : e[u]) {
        if (v == fa) continue;
        dfs(v,u);
    }
    ll sum = 0;tot = 0;
    int t = (deg[u]+1)/2-1;
    for (int i = 0; i <= t; i++) tmp[i] = val[i] = 0;
    for (auto v : e[u]) {
        if (v == fa) continue;
        ll p = max(f[v][0]+min(w[u],w[v]),f[v][1]+w[u]);
        ll q = max(f[v][0]+w[v],f[v][1]+m);
        if (q > p) val[++tot] = q-p;
        sum += p;
    }
    sort(val+1,val+tot+1,greater<ll>());
    for (int i = 1; i <= t; i++) tmp[i] = tmp[i-1] + val[i];
    f[u][0] = sum + tmp[t];
    if (t > 0) f[u][1] = sum + tmp[t-1];
    else f[u][1] = -0x3f3f3f3f3f3f3f3f;
}
signed main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(n),read(m);
    for (int i = 1; i <= n; i++) read(w[i]);
    for (int i = 1; i < n; i++) {
        int u,v;
        read(u),read(v);
        e[u].push_back(v),e[v].push_back(u);
        deg[u]++,deg[v]++;
    }
    dfs(1,0);
    printf("%lld",max(f[1][0],f[1][1]));
    return 0;
}