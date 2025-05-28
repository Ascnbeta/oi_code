#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5+30;
const ll mod = 1e9+7;
inline void read(int &x) {
    x=0;int f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){
        if (ch=='-')f=-1;
        ch=getchar();
    }
    while (ch>='0'&&ch<='9'){
        x=(x<<3)+(x<<1)+(ch^48);
        ch=getchar();
    }
    x*=f;
}
int n,k;
vector<int> e[maxn];
ll c[maxn],f[maxn][4];
void dfs(int u,int fa) {
    if (c[u]) {
        f[u][c[u]] = 1;
        for (auto v : e[u]) {
            if (v == fa) continue;
            dfs(v,u);
            if (c[u] == 1) f[u][1] = (f[u][1]*(f[v][2]+f[v][3]))%mod;
            if (c[u] == 2) f[u][2] = (f[u][2]*(f[v][1]+f[v][3]))%mod;
            if (c[u] == 3) f[u][3] = (f[u][3]*(f[v][1]+f[v][2]))%mod;
        }
    }else{
        f[u][1] = f[u][2] = f[u][3] = 1;
        for (auto v : e[u]) {
            if (v == fa) continue;
            dfs(v,u);
            f[u][1] = (f[u][1]*(f[v][2]+f[v][3]))%mod;
            f[u][2] = (f[u][2]*(f[v][1]+f[v][3]))%mod;
            f[u][3] = (f[u][3]*(f[v][1]+f[v][2]))%mod;
        }
    }
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(n),read(k);
    for (int i = 1; i < n; i++) {
        int u,v;
        read(u),read(v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 1; i <= k; i++) {
        int u,x;
        read(u),read(x);
        c[u] = x;
    }
    dfs(1,0);
    if (c[1]) printf("%lld",f[1][c[1]]);
    else printf("%lld",(f[1][1]+f[1][2]+f[1][3])%mod);
    return 0;
}