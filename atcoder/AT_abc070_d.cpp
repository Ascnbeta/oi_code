#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
int n,q,k;
struct edge{
    int to,nxt,val;
}e[200005];
int head[100005],tot = 1;
bool vis[100005];
int d[100005];
void add(int u,int v,int w) {
    e[tot].to = v;
    e[tot].val = w;
    e[tot].nxt = head[u];
    head[u] = tot++;
}
void dfs(int st,int len) {
    vis[st] = true;
    d[st] = len;
    for (int i = head[st]; i; i= e[i].nxt) {
        if (vis[e[i].to]) continue;
        dfs(e[i].to,len + e[i].val);
    }
}
signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n-1; i++) {
        int x,y,z;
        cin >> x >> y >> z;
        add(x,y,z);
        add(y,x,z);
    }
    cin >> q >> k;
    dfs(k,0);
    for (int i = 1; i <= q; i++) {
        int x,y;
        cin >> x >> y;
        cout << d[x] + d[y] << '\n';
    }
    return 0;
}