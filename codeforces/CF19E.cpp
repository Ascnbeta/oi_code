#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+30;
const int maxm = 1e4+30;
int n,m;
vector<int> e[maxn],id[maxn];
inline void read(int &x) {
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
int color[maxn],cnt;bool g[maxn];
void dfs(int u,int c) {
    color[u] = c;
    for (int i = 0; i < e[u].size(); i++) {
        int v = e[u][i];
        if (color[v]) {
            if (g[id[u][i]]) continue;
            g[id[u][i]] = true;
            if (color[v] == color[u]) ++cnt;
            continue;
        }
        dfs(v,c^1);
    }
}
int sum[maxn],f[maxn];bool vis[maxn],chs[maxn],vise[maxn];
vector<int> ans;
void solve(int u,int fa,int p) {
    vis[u] = true;
    for (int i = 0; i < e[u].size(); i++) {
        int v = e[u][i];
        if (v == fa || vise[id[u][i]]) continue;
        if (vis[v]) {
            if (vise[id[u][i]]) continue;
            if (color[v]==color[u]) {
                if (cnt == 1) {
                    if (!chs[id[u][i]]) ans.push_back(id[u][i]);
                    chs[id[u][i]] = true;
                }
                sum[u] += 1,sum[v] -= 1;
            }
            else sum[u] -= 1,sum[v] += 1;
            vise[id[u][i]] = true;
        }else{
            f[v] = u;
            vise[id[u][i]] = true;
            solve(v,u,id[u][i]);
            sum[u] += sum[v];
        }
    }
    if (sum[u] == cnt) {
        if (!chs[p]) ans.push_back(p);
        chs[p] = true;
    }
}
int cnts = 0;
int main() {
#ifdef LOCAL
    freopen("E:/codes/exe/a.in","r",stdin);
    freopen("E:/codes/exe/a.out","w",stdout);
#endif
    read(n),read(m);
    for (int i = 1; i <= m; i++) {
        int u,v;
        read(u),read(v);
        e[u].push_back(v);id[u].push_back(i);
        e[v].push_back(u);id[v].push_back(i);
    }
    for (int i = 1; i <= n; i++) if (!color[i]) dfs(i,2);
    if (cnt == 0) {
        cout << m << '\n';
        for (int i = 1; i <= m; i++) cout << i << ' ';
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            solve(i,0,0);
        }
    }
    cout << ans.size() << '\n';
    sort(ans.begin(),ans.end());
    for (auto i : ans) cout << i << ' ';
    return 0;
}