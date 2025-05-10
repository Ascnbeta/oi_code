#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5e2+30;
int n,m;
int a[maxn],b[maxn],g[maxn],l[maxn],minn[maxn];
int mul[maxn][maxn],gcd[maxn][maxn],lcm[maxn][maxn];
struct edge{
    int to,nxt,g,l;
}e[maxn<<1];
int head[maxn],tot;
inline void add(int u,int v,int g,int l) {
    e[++tot].to = v;
    e[tot].nxt = head[u];
    e[tot].g = g;
    e[tot].l = l;
    head[u] = tot;
}
bool vis[maxn],f;
int c[maxn];
vector<int> vec;
void dfs(int u,int val) {
    vec.push_back(u);
    vis[u] = true;
    for (int i = head[u]; i; i = e[i].nxt) {
        if (!f) return;
        int v = e[i].to;
        if (vis[v]) {
            if (c[v]*val != e[i].g * e[i].l || __gcd(c[v],val) != e[i].g || c[v]*val/__gcd(c[v],val) != e[i].l) {
                f = false;
                return;
            }
        }else{
            c[v] = e[i].g*e[i].l/val;
            if (c[v]*val != e[i].g * e[i].l || __gcd(c[v],val) != e[i].g || c[v]*val/__gcd(c[v],val) != e[i].l) {
                f = false;
                return;
            }
            dfs(v,c[v]);
        }
    }
}
signed main () {
    #ifdef LOCAL
        freopen("D:/codes/exe/a.in","r",stdin);
        freopen("D:/codes/exe/a.out","w",stdout);
    #endif
    memset(minn,0x3f,sizeof(minn));
    cin >> n;
    cin >> m;
    for (int i = 1; i <= m; i++) cin >> a[i],++a[i];
    cin >> m;
    for (int i = 1; i <= m; i++) cin >> b[i],++b[i];
    cin >> m;
    for (int i = 1; i <= m; i++) cin >> g[i];
    cin >> m;
    for (int i = 1; i <= m; i++) cin >> l[i],minn[a[i]]=min(minn[a[i]],l[i]),minn[b[i]]=min(minn[b[i]],l[i]);
    for (int i = 1; i <= m; i++) {
        add(a[i],b[i],g[i],l[i]);
        add(b[i],a[i],g[i],l[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            bool f1 = false;
            for (int j = 1; j <= min(minn[i],10000ll); j++) {
                vec.clear();
                f = true;
                c[i] = j;
                dfs(i,j);
                if (f) {
                    f1 = true;
                    break;
                }
                else {
                    for (int k : vec) vis[k] = false;
                }
            }
            if (!f1) {
                puts("Solution does not exist");
                return 0;
            }
        }
    }
    puts("Solution exists");
    return 0;
}