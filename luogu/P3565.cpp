#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;
const int maxn = 5e3+10;
int n;
vector<int> e[maxn];
ll f[maxn][maxn],dep[maxn];
void dfs1(int u,int fa) {
    dep[u] = dep[fa] + 1;
    f[u][dep[u]] = 1;
    for (auto v : e[u]) {
        if (v == fa) continue;
        dfs1(v,u);
        for (int i = dep[u]+1; i <= n; i++) f[u][i] += f[v][i];
    }
}
void dfs2(int u,int fa) {

}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u,v;
        cin >> u >> v;
        e[u].push_back(v),e[v].push_back(u);
    }
    dfs1(1,0);
    dfs2(1,0);
    return 0;
}