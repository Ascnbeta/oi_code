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
template <typename T>
inline void write(T x) {
    if (x<0) x=-x,putchar('-');
    if (x/10) write(x/10);
    putchar(x%10+'0');
}
const int maxn = 1e5+5;
const ll mod = 998244353;
ll a[maxn];
struct operation {
    int tp;ll x,y;
}op[maxn];
vector<int> g[maxn];
int ind[maxn];
ll mul[maxn];
void dfs(int u) {
    if (mul[u] != -1) return;
    if (op[u].tp == 1) mul[u] = 1;
    else if(op[u].tp == 2) mul[u] = op[u].x;
    else {
        mul[u] = 1;
        for (auto v : g[u]) {
            dfs(v);
            mul[u] *= mul[v],mul[u] %= mod;
        }
    }
}
int p[maxn];ll f[maxn],k[maxn];
int n,m;
inline void topo() {
    queue<int> q;
    for (int i = 1; i <= m; i++) if (!ind[i]) q.push(i);
    while (!q.empty()) {
        int u = q.front();q.pop();
        if (op[u].tp == 1) {
            k[op[u].x] += op[u].y * f[u] % mod;
            k[op[u].x] %= mod;
        }else if(op[u].tp == 2) {
            continue;
        }else{
            for (int i = g[u].size()-1; i >= 0; i--) {
                int v = g[u][i];
                f[v] += f[u],f[v] %= mod;
                f[u] *= mul[v],f[u] %= mod;
                --ind[v];
                if (!ind[v]) q.push(v);
            }
        }
    }
}
int q;
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(n);
    for (int i = 1; i <= n; i++) read(a[i]);
    read(m);
    for (int i = 1; i <= m; i++) {
        int tp;read(tp);
        if (tp == 1) {
            int p;ll v;
            read(p),read(v);
            op[i] = {1,p,v};
        }else if(tp == 2) {
            ll v;read(v);
            op[i] = {2,v,0};
        }else{
            int c;read(c);
            op[i] = {3,0,0};
            for (int j = 1; j <= c; j++) {
                int x;read(x);
                g[i].push_back(x);
                ind[x]++;
            }
        }
    }
    memset(mul,-1,sizeof(mul));
    for (int i = 1; i <= m; i++) {
        if (mul[i] == -1) dfs(i);
    }
    read(q);
    for (int i = 1; i <= q; i++) read(p[i]);
    ll base = 1;
    for (int i = q; i >= 1; i--) {
        if (op[p[i]].tp == 1) {
            f[p[i]] += base,f[p[i]] %= mod;
        }else if(op[p[i]].tp == 2) {
            base *= op[p[i]].x,base %= mod;
        }else{
            f[p[i]] += base,f[p[i]] %= mod;
            base *= mul[p[i]],base %= mod;
        }
    }
    topo();
    for (int i = 1; i <= n; i++) {
        write((a[i]*base%mod+k[i])%mod),putchar(' ');    
    }
    return 0;
}