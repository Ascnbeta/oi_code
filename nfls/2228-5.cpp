#include <bits/stdc++.h>
#define ll long long
using namespace std;
inline void read(int &x) {
    x=0;
    int f=1;char ch=getchar();
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
const int maxn = 70;
int n;
int a[maxn],b[maxn];
vector<int> e[maxn];
ll f[maxn][2],sum[maxn],son[maxn];
void dfs(int u,int fa) {
    f[u][1] = 1;f[u][0] = 1;
    for (auto v : e[u]) {
        if (v == fa) continue;
        dfs(v,u);
        f[u][0] += sum[v];
        f[u][1] *= (f[v][1]+1);
        sum[u] += sum[v];
    }
    sum[u] += f[u][1];
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(n);
    for (int i = 1; i <= n; i++) read(a[i]);
    read(n);
    for (int i = 1; i <= n; i++) read(b[i]);
    ++n;
    for (int i = 1; i < n; i++) {
        e[a[i]].push_back(b[i]);
        e[b[i]].push_back(a[i]);
    }
    dfs(1,0);
    printf("%lld",f[1][1]+f[1][0]);
    return 0;
}