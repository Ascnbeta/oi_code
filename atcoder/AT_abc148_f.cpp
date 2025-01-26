#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 6;
int n,p,q;
bool vis[N];
int da[N],dt[N],ans = -1;
struct edge{
    int nxt,to;
}e[2*N];
int head[N],tot = 1;
void add(int u,int v) {
    e[tot].nxt = head[u];
    e[tot].to = v;
    head[u] = tot++;
}
void dfs1(int x,int s) {
    da[x] = s;
    vis[x] = true;
    for (int i = head[x];i;i = e[i].nxt) {
        if (vis[e[i].to]) continue;
        dfs1(e[i].to,s+1);
    }
}
void dfs2(int x,int s) {
    dt[x] = s;
    vis[x] = true;
    for (int i = head[x];i;i = e[i].nxt) {
        if (vis[e[i].to]) continue;
        dfs2(e[i].to,s+1);
    }
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> p >> q;
    for (int i = 1; i <= n-1; i++) {
        int x,y;
        cin >> x >> y;
        add(x,y);
        add(y,x);
    }
    dfs1(q,0);
    for (int i = 1; i <= n ;i++) vis[i] = false;
    dfs2(p,0);
//    for (int i = 1; i <= n; i++) {
//        cout << da[i] <<"  " << dt[i] << endl;
//    }
    for (int i = 1; i <= n; i++) {
        if (da[i] > ans) {
            if (dt[i] < da[i]) {
                ans = da[i]-1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}