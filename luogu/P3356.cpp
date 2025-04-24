#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int maxn = 1e4+30;
const int maxm = 3e4+30;
int p,q,num;
int mp[102][102];
bool is_b[maxn];
struct egde{
    int to,nxt,f,cst;
}e[maxm<<3];
int head[maxn],tot = 1;
struct node{
    int x,y;
}a[maxn];
int cnt;
inline void add(int u,int v,int w,int cst) {
    e[++tot].to = v;
    e[tot].f = w;
    e[tot].cst = cst;
    e[tot].nxt = head[u];
    head[u] = tot;
    e[++tot].to = u;
    e[tot].f = 0;
    e[tot].cst = -cst;
    e[tot].nxt = head[v];
    head[v] = tot;
}
int dis[maxn];
bool vis[maxn];
inline bool spfa(int s,int t) {
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[s] = 0;
    queue<int> q;
    vis[s] = true;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();

        for (int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].to,w = e[i].cst,f = e[i].f;
            if (f > 0 && dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                if (!vis[v]) vis[v] = true,q.push(v);
            }
        }
        q.pop();
        vis[u] = false;
    }
    return dis[t] < inf;
}
inline int dfs(int s,int flw,int t) {
    if (s == t || flw <= 0) return flw;
    int rst = flw;
    vis[s] = true;
    for (int i = head[s]; i ; i = e[i].nxt) {
        int v = e[i].to,w = e[i].cst,f = e[i].f;
        if (f > 0 && dis[s] + w == dis[v] && !vis[v]) {
            int tmp = dfs(v,min(rst,f),t);
            rst -= tmp;
            e[i].f -= tmp;
            e[i^1].f += tmp;
            if (rst <= 0) break;
        }
    }
    vis[s] = false;
    return flw - rst;
}
inline void dinic(int s,int t) {
   pair<int,int> ans = {0,0};
    while (spfa(s,t)) {
        int tmp = dfs(s,inf,t);
        ans.first += tmp;
        ans.second += tmp*dis[t];
    }
    // cout << ans.first << ' ' << ans.second << '\n';
    // cout << ans << '\n';
}
inline void print(int id,int u) {
    int tmp = u - 2 * p * q;
    for (int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].to,w = e[i].f;
        // cout << v << ' ' << w << '\n';
        if (w == 0) continue;
        int vt = v - 2 * p * q;
        if (tmp + 1 == vt) cout << id << " 1\n";
        else cout << id << " 0\n";
        --e[i].f;
        print(id,v);
        break;
    }
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> num >> q >> p;
    for (int i = 1; i <= p; i++) {
        for (int j = 1; j <= q; j++) {
            mp[i][j] = ++cnt;
        }
    }
    int s = p*q*3+1,t = p*q*3+2;
    add(s,1,num,0);
    add(p*q*2,t,num,0);
    for (int i = 1; i <= p; i++) {
        for (int j = 1; j <= q; j++) {
            int x;
            cin >> x;
            if (x == 0) {
                add(mp[i][j],p*q+mp[i][j],inf,0);
            }else if (x == 2) {
                add(mp[i][j],p*q+mp[i][j],1,-1);
                add(mp[i][j],p*q+mp[i][j],inf,0);
            }else{
                is_b[mp[i][j]] = true;
            }
        }
    }
    for (int i = 1; i < p; i++) {
        for (int j = 1; j <= q; j++) {
            add(p*q+mp[i][j],mp[i+1][j],inf,0);
        }
    }
    for (int i = 1; i <= p; i++) {
        for (int j = 1; j < q; j++) {
            add(p*q+mp[i][j],mp[i][j+1],inf,0);
        }
    }
    dinic(s,t);
    for (int i = 1+p*q; i < 2*p*q; i++) {
        if (is_b[i-p*q]) continue;
        for (int j = head[i]; j; j = e[j].nxt) {
            int v = e[j].to,f = e[j].f;
            if (v == i-p*q) continue;
            if (f == inf) continue;
            add(i+p*q,v+2*p*q,inf-f,0);
            // cout << i-p*q << ' ' << v << '\n';
        }
    }
    for (int i = 1; i <= num; i++) {
        print(i,1+2*p*q);
    }
    return 0;
}