#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 1e5+30;
int n,K;
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
vector<int> e[maxn];
const ll mod = 1e9+7;
int f[maxn][103][2][2],tmp[103][2][2],siz[maxn];
void dfs(int u,int fa) {
    f[u][1][1][0] = 1;
    f[u][0][0][0] = 1;
    siz[u] = 1;
    for (auto v : e[u]) {
        if (v == fa) continue;
        dfs(v,u);
        memcpy(tmp,f[u],sizeof(tmp));
        memset(f[u],0,sizeof(f[u]));
        for (int j = 0; j <= min(K,siz[u]+siz[v]); j++) {
            for (int k = max(0,j-siz[u]); k <= min(siz[v],j); k++) {
                f[u][j][0][0] = (1ll*f[u][j][0][0]+1ll*tmp[j-k][0][0]*f[v][k][0][1]%mod)%mod;
                if (j >= 1) f[u][j][1][0] = (1ll*f[u][j][1][0]+1ll*tmp[j-k][1][0]*((1ll*f[v][k][0][1]+f[v][k][0][0])%mod)%mod)%mod;
                f[u][j][0][1] = (1ll*f[u][j][0][1]+1ll*tmp[j-k][0][0]*f[v][k][1][1]%mod+1ll*tmp[j-k][0][1]*((1ll*f[v][k][0][1]+f[v][k][1][1])%mod)%mod)%mod;
                if (j >= 1) f[u][j][1][1] = (1ll*f[u][j][1][1]+(1ll*tmp[j-k][1][0]*(1ll*f[v][k][1][0]+f[v][k][1][1])%mod+1ll*tmp[j-k][1][1]*(1ll*f[v][k][0][0]+1ll*f[v][k][0][1]+1ll*f[v][k][1][0]+1ll*f[v][k][1][1])%mod)%mod)%mod;
            }
        }
        siz[u] += siz[v];
    }

}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(n),read(K);
    for (int i = 1; i < n; i++) {
        int u,v;
        read(u),read(v);
        e[u].push_back(v),e[v].push_back(u);
    }
    dfs(1,0);
    printf("%d",(f[1][K][0][1]+f[1][K][1][1])%mod);
    return 0;
}