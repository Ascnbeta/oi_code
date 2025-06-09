#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+20;
const double eps = 1e-6;
int n,s,t;
inline void read(int &x) {
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
struct edge{
    int to;double w;int op;
};
vector<edge> e[maxn];
double dis[maxn];bool f[maxn];int cnt[maxn];
queue<int> q;
inline bool spfa(double t) {
    for (int i = 0; i <= n; ++i) dis[i] = -2e9,f[i] = false,cnt[i] = 0;
    q={};
    f[0] = true,dis[0] = 0;
    q.push(0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        f[u] = false;
        for (auto i : e[u]) {
            int v = i.to;
            double w = i.w;
            if (i.op == 1) {
                w = log2(w-t);
            }else if (i.op == 2) {
                w = -log2(w+t);
            }
            if (dis[v] < dis[u] + w) {
                dis[v] = dis[u] + w;
                cnt[v] = cnt[u] + 1;
                if (cnt[v] > n) return true;
                if (!f[u]) {
                    q.push(v);
                    f[v] = true;
                }
            }
        }
    }
    return false;
}
int main() {
#ifdef LOCAL
    freopen("E:/codes/exe/a.in","r",stdin);
    freopen("E:/codes/exe/a.out","w",stdout);
#endif
    read(n),read(s),read(t);
    for (int i = 1; i <= n; i++) e[0].push_back({i,0,3});
    double l = 0,r = 2e9;
    for (int i = 1; i <= s; i++) {
        int o,a,b,k;
        read(o),read(a),read(b),read(k);
        if (o == 1) r = min((double)k,r);
        e[b].push_back({a,(double)k,o});
    }
    for (int i = 1; i <= t; i++) {
        int x,y;
        read(x),read(y);
        e[0].push_back({x,log2(y),3});
        e[x].push_back({0,-log2(y),3});
    }
    if (!spfa(0)) {
        puts("-1");return 0;
    }
    while (r-l >= eps) {
        double mid = (l + r) / 2;
        if (spfa(mid)) {
            l = mid;
        }else{
            r = mid;
        }
    }
    printf("%.10f",l);
    return 0;
}