#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
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
inline void write(int x) {
    static int st[16];int top = 0;
    do{
        st[++top] = x%10;
        x/=10;
    }while(x);
    while (top) putchar(st[top--]+'0');
}
const int maxn = 3e5+30;
const ld eps = 1e-8;
int n,m;
int a[maxn];ll h[maxn],b[maxn];
struct knight{
    ld s;int id;
    bool operator < (const knight &y) const{
        return s > y.s;
    }
};
priority_queue<knight> q[maxn];
vector<int> e[maxn];
ld tagp[maxn],tagm[maxn];
int death[maxn],ansc[maxn],pt[maxn],dep[maxn],st[maxn];
void dfs(int u,int fa) {
    int son = u;
    dep[u] = dep[fa] + 1;
    for (auto v : e[u]) {
        if (v == fa) continue;
        dfs(v,u);
        if (q[pt[v]].size() > q[pt[son]].size()) son = v;
    }
    if (son != u) {
        while (!q[pt[u]].empty()) {
            auto tmp = q[pt[u]].top();
            q[pt[u]].pop();
            tmp.s -= tagp[pt[son]];
            tmp.s /= tagm[pt[son]];
            q[pt[son]].push(tmp);
        }
    }
    for (auto v : e[u]) {
        if (v == fa || v == son) continue;
        while (!q[pt[v]].empty()) {
            auto tmp = q[pt[v]].top();
            q[pt[v]].pop();
            tmp.s *= tagm[pt[v]];
            tmp.s += tagp[pt[v]];
            tmp.s -= tagp[pt[son]];
            tmp.s /= tagm[pt[son]];
            q[pt[son]].push(tmp);
        }
    }
    pt[u] = pt[son];
    while (!q[pt[u]].empty() && q[pt[u]].top().s*tagm[pt[u]]+tagp[pt[u]] < h[u]) {
        death[q[pt[u]].top().id] = u;
        ++ansc[u];
        q[pt[u]].pop();
    }
    if (a[u] == 0) tagp[pt[u]] += b[u];
    else tagp[pt[u]] *= b[u],tagm[pt[u]] *= b[u];
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(n),read(m);
    for (int i = 1; i <= n; i++) read(h[i]),pt[i]=i,tagp[i]=0,tagm[i]=1;
    for (int i = 2; i <= n; i++) {
        int x;read(x),read(a[i]),read(b[i]);
        e[x].push_back(i);
    }
    for (int i = 1; i <= m; i++) {
        ll s;
        read(s),read(st[i]);
        q[st[i]].push({(ld)s,i});
    }
    dfs(1,0);
    for (int i = 1; i <= n; i++) write(ansc[i]),putchar('\n');
    for (int i = 1; i <= m; i++) write(dep[st[i]]-dep[death[i]]),putchar('\n');
    return 0;
}