#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 1e5+30;
int n,m;
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
ll c[maxn],l[maxn];
vector<int> e[maxn];
priority_queue<int> q[maxn];
int pt[maxn];
ll sum[maxn],ans;
void dfs(int u,int fa) {
    int son = u;
    for (auto v : e[u]) {
        if (v == fa) continue;
        dfs(v,u);
        if (q[pt[v]].size() > q[pt[son]].size()) son = v;
    }
    q[pt[son]].push(c[u]),sum[pt[son]] += c[u];
    for (auto v : e[u]) {
        if (v == fa || v == son) continue;
        while (!q[pt[v]].empty()) {
            q[pt[son]].push(q[pt[v]].top());
            sum[pt[son]] += q[pt[v]].top();
            q[pt[v]].pop();
        }
    }
    pt[u] = pt[son];
    while (sum[pt[u]] > m) {
        sum[pt[u]] -= q[pt[u]].top();
        q[pt[u]].pop();
    }
    ans = max(ans,(long long)q[pt[u]].size()*l[u]);
}
int main() {
#ifdef LOCAL
    freopen("E:/codes/exe/a.in","r",stdin);
    freopen("E:/codes/exe/a.out","w",stdout);
#endif
    read(n),read(m);
    for (int i = 1; i <= n; i++) {
        int v;
        read(v),read(c[i]),read(l[i]);
        if (v) e[v].push_back(i);
        pt[i] = i;
    }
    dfs(1,0);
    printf("%lld",ans);
    return 0;
}