#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+30;
const double eps = 1e-20;
int n;
struct edge{
    int to,nxt;
    double p;
};
vector<edge> e((maxn<<1)+30);
vector<int> head(maxn+30);
int tot;
inline void add(int u,int v,double w) {
    e[++tot].to = v;
    e[tot].p = w;
    e[tot].nxt = head[u];
    head[u] = tot;
}
double np[maxn];
double dp[maxn],ans;
void dfs1(int u,int fa) {
    dp[u] = np[u];
    for (int i = head[u]; i ; i = e[i].nxt) {
        int v = e[i].to;
        double w = e[i].p;
        if (v == fa) continue;
        dfs1(v,u);
        double W = dp[v]*w;
        dp[u] = dp[u] + W - W*dp[u];
    }
}
void dfs2(int u,int fa) {
    ans += dp[u];
    for (int i = head[u]; i ; i = e[i].nxt) {
        int v = e[i].to;
        double w = e[i].p;
        if (v == fa) continue;
        double W = dp[v]*w;
        // cout << W << '\n';
        if (W != 1) {
            double tmp = (dp[u]-W)/(1-W);
            dp[v] = dp[v]+tmp*w-dp[v]*tmp*w;
        } 
        dfs2(v,u);
    }
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u,v,p;
        cin >> u >> v >> p;
        add(u,v,p/100.0);
        add(v,u,p/100.0);
    }
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        np[i] = x/100.0;
    }
    dfs1(1,0);
    dfs2(1,0);
    // for (int i = 1; i <= n; i++) {
    //     cout << dp[i] << ' ';
    // }
    // cout << '\n';
    cout << fixed << setprecision(6) << ans << '\n';
    return 0;
}