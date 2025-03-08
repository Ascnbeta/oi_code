#include <bits/stdc++.h>
using namespace std;
int n,ans;
struct edge{
    int to,nxt,w;
}e[2000004];
int head[10005],tot;
inline void add(int u,int v,int w) {
    e[++tot].to = v;
    e[tot].nxt = head[u];
    e[tot].w = w;
    head[u] = tot;
}
struct node{
    int p,w;
    bool operator < (const node &y) const{
        return w > y.w;
    }
};
//priority_queue<node> q;
bool f[10004];int dis[10004];
// inline void dij(int s) {
//     q.push({s,0});
//     while (!q.empty()) {
//         node t = q.top();
//         q.pop();
//         if (f[t.p]) continue;
//         f[t.p] = true;
//         for (int i = head[t.p]; i; i = e[i].nxt) {
//             int v = e[i].to;
//             if (dis[v] < dis[t.p] + e[i].w) {
//                 dis[v] = dis[t.p] + e[i].w;
//                 q.push({v,dis[v]});
//             }
//         } 
//     }
// }
queue<int> q;
inline void spfa(int s) {
    q.push(s);
    f[s] = true;
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        f[t] = false;
        for (int i = head[t]; i; i = e[i].nxt) {
            int v = e[i].to;
            if (dis[v] < dis[t] + e[i].w) {
                dis[v] = dis[t] + e[i].w;
                if (!f[t]) {
                    q.push(v);
                    f[v] = true;
                }
            }
        }
    }
}
int main () {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int o,l;
        cin >> o >> l;
        int c;
        cin >> c;
        bool t = false;
        while (c != 0) {
            t = true;
            add(c,i,l);
            cin >> c;
        }
        if (!t) add(0,i,l);
    }
    spfa(0);
    for (int i = 1; i <= n; i++) ans = max(ans,dis[i]);
    cout << ans << '\n';
    return 0;
}