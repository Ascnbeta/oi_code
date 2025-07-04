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
inline void write(T x) {
    if (x<0) putchar('-'),x=-x;
    if (x/10) write(x/10);
    putchar(x%10+'0');
}
const int maxn = 5e4+5;
const int maxm = 1e5+5;
int n,m,q;
struct edge{
    int u,v,w,id;
    bool operator < (const edge &y) const {
        return w < y.w;
    }
}e1[maxm];
vector<edge> e[maxn];
int vis[maxn];
int cnt = 0;
void dfs(int u,int t,int p) {
    vis[u] = p;++cnt;
    for (auto i : e[u]) {
        int v = i.v;
        if (vis[v]==p||i.w<t) continue;
        dfs(v,t,p);
    }
}
struct ask{
    int op,x,y,id;
    bool operator < (const ask &t) const {
        return y < t.y;
    }
}a[maxm];
int father[maxn],siz[maxn],ans[maxm];
inline int find(int x) {
    int t = x;
    while (x != father[x]) x = father[x];
    int w;
    while (t != father[t]) w = father[t],father[t] = x,t = w;
    return x;
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(n),read(m);
    for (int i = 1; i <= m; i++) {
        int u,v,w;
        read(u),read(v),read(w);
        e[u].push_back({u,v,w,i}),e[v].push_back({v,u,w,i});
        e1[i] = {u,v};
    }
    read(q);
    if ((n+m)*q <= 5e8) {
        while (q--) {
            int op,x,y;
            read(op),read(x),read(y);
            if (op == 1) {
                int u = e1[x].u,v = e1[x].v;
                for (auto &i : e[u]) {
                    if (i.id == x) {
                        i.w = y;
                        break;
                    }
                }
                for (auto &i : e[v]) {
                    if (i.id == x) {
                        i.w = y;
                        break;
                    }
                }
            }else{
                cnt = 0;
                dfs(x,y,q);
                write(cnt),putchar('\n');
            }
        }//13pts
    }else{
        bool f4 = true;
        for (int i = 1; i <= q; i++) {
            read(a[i].op),read(a[i].x),read(a[i].y);a[i].id = i;
            if (f4&&a[i].op == 1) f4 = false;
        }
        if (f4) {
            sort(a+1,a+q+1);sort(e1+1,e1+m+1);
            for (int i = 1; i <= n; i++) father[i] = i,siz[i] = 1;
            int cur = 1;
            for (int i = 1; i <= q; i++) {
                while (cur <= m && e1[cur].w <= a[i].y) {
                    int p = find(e1[i].u),q = find(e1[i].v);
                    if (p != q) father[p] = q,siz[q] += siz[p];
                    ++cur;
                }
                ans[a[i].id] = siz[find(a[i].x)];
            }
            for (int i = 1; i <= q; i++) {
                write(ans[i]),putchar('\n');
            }
            return 0;
        }//14pts
    }
    return 0;
}