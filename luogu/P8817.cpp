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
inline void write (T x) {
    if (x<0) putchar('-'),x=-x;
    if (x/10) write(x/10);
    putchar('0'+x%10);
}
const int maxn = 2.5e3+5;
const int maxm = 1e4+5;
int n,m,k;
ll s[maxn];vector<int> e[maxn];
int dis[maxn][maxn];bool vis[maxn];
ll sol[maxn][5];int id[maxn][5];
inline void bfs(int s) {
    queue<int> q;
    memset(vis,0,sizeof(vis));
    dis[s][s] = 0;
    q.push(s);
    vis[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto &v : e[u]) {
            if (!vis[v]) {
                q.push(v),vis[v] = true;
                dis[s][v] = dis[s][u] + 1;
            }
        }
    }
    dis[s][s] = 0x3f3f3f3f;
}
ll ans;
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(n),read(m),read(k);++k;
    for (int i = 2; i <= n; i++) read(s[i]);
    for (int i = 1; i <= m; i++) {
        int u,v;
        read(u),read(v);
        e[u].push_back(v),e[v].push_back(u);
    }
    memset(dis,0x3f,sizeof(dis));
    for (int i = 1; i <= n; i++) bfs(i);
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= n; j++) {
            if (dis[1][j] > k || dis[j][i] > k) continue;
            if (s[j]>sol[i][1]) {
                sol[i][3] = sol[i][2];
                id[i][3] = id[i][2];
                sol[i][2] = sol[i][1];
                id[i][2] = id[i][1];
                sol[i][1] = s[j];
                id[i][1] = j;
            }else if (s[j] > sol[i][2]) {
                sol[i][3] = sol[i][2];
                id[i][3] = id[i][2];
                sol[i][2] = s[j];
                id[i][2] = j;
            }else if (s[j] > sol[i][3]) {
                sol[i][3] = s[j];
                id[i][3] = j;
            }
        }
        sol[i][1] += s[i],sol[i][2] += s[i],sol[i][3] += s[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (dis[i][j] > k) continue;
            for (int p = 1; p <= 3; p++) {
                for (int q = 1; q <= 3; q++) {
                    if (!id[i][p] || !id[j][q]) continue;
                    if (id[i][p] == j || id[j][q] == i || id[i][p] == id[j][q]) continue;
                    ans = max(ans,sol[i][p]+sol[j][q]);
                }
            }
        }
    }
    write(ans);
    return 0;
}