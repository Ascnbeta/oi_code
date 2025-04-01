#include <bits/stdc++.h>
#define ls (p<<1)
#define rs (p<<1|1)
#define int long long
using namespace std;
const int maxn = 1e5+30;
int n,Q,s;
struct edge{
    int to,nxt,w;
}e[2500003];
int head[maxn<<4],tot;
inline void add(int u,int v,int w) {
    e[++tot].to = v;
    e[tot].nxt = head[u];
    e[tot].w = w;
    head[u] = tot;
}
inline void build(int p,int l,int r) {
    if (l == r) {
        return;
    }
    int mid = (l + r) >> 1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    add(p,ls,0);
    add(p,rs,0);
    add(ls+(n<<2),p+(n<<2),0);
    add(rs+(n<<2),p+(n<<2),0);
}
inline int query(int p,int pos,int l,int r) {
    if (l == r) return p;
    int mid = (l + r) >> 1;
    if (pos <= mid) return query(ls,pos,l,mid);
    else return query(rs,pos,mid+1,r);
}
inline void adda(int p,int k,int w,int s,int e,int l,int r) {
    if (s <= l && r <= e) {
        add(k,p,w);
        return;
    }
    int mid = (l + r) >> 1;
    if (s <= mid) adda(ls,k,w,s,e,l,mid);
    if (e > mid) adda(rs,k,w,s,e,mid+1,r);
    return;
}
inline void addb(int p,int k,int w,int s,int e,int l,int r) {
    if (s <= l && r <= e) {
        add(p+(n<<2),k,w);
        return;
    }
    int mid = (l + r) >> 1;
    if (s <= mid) addb(ls,k,w,s,e,l,mid);
    if (e > mid) addb(rs,k,w,s,e,mid+1,r);
    return;
}
int dis[maxn<<3];
struct node{
    int p,w;
    bool operator < (const node &y) const{
        return w > y.w;
    }
};
priority_queue<node> q;
bool vis[maxn<<3];
inline void print(int p,int l,int r) {
    if (l == r) {
        if (dis[p] != LONG_LONG_MAX) cout << dis[p] << ' ';
        else cout << -1 << ' ';
        return;
    }
    int mid = (l + r) >> 1;
    print(ls,l,mid);
    print(rs,mid+1,r);
}
inline void dij(int s) {
    for (int i = 1; i <= (n<<3); i++) dis[i] = LONG_LONG_MAX;
    dis[s] = 0;
    q.push({s,0});
    while (!q.empty()) {
        node t = q.top();
        q.pop();
        if (vis[t.p]) continue;
        vis[t.p] = true;
        for (int i = head[t.p]; i; i = e[i].nxt) {
            int v = e[i].to,w = e[i].w;
            if (vis[v]) continue;
            if (dis[v] > dis[t.p] + w) {
                dis[v] = dis[t.p] + w;
                q.push({v,dis[v]});
            }
        } 
    }
    print(1,1,n);
}
signed main() {
#ifdef LOCAL
    freopen("E:/codes/exe/a.in","r",stdin);
    freopen("E:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> Q >> s;
    build(1,1,n);
    for (int i = 1; i <= n; i++) {
        add(query(1,i,1,n),query(1,i,1,n)+(n<<2),0);
        add(query(1,i,1,n)+(n<<2),query(1,i,1,n),0);
    }
    // cout << query(1,1,1,3) << '\n';
    // dij(1);
    for (int i = 1; i <= Q; i++) {
        int opt,u;
        cin >> opt >> u;
        if (opt == 1) {
            int v,w;
            cin >> v >> w;
            add(query(1,u,1,n)+(n<<2),query(1,v,1,n),w);
        }else if (opt == 2) {
            int l,r,w;
            cin >> l >> r >> w;
            adda(1,query(1,u,1,n)+(n<<2),w,l,r,1,n);
        }else{
            int l,r,w;
            cin >> l >> r >> w;
            addb(1,query(1,u,1,n),w,l,r,1,n);
        }
    }
    dij(query(1,s,1,n));
    return 0;
}