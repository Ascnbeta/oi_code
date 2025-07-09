#include <bits/stdc++.h>
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
    if (x<0) x=-x,putchar('-');
    if (x/10) write(x/10);
    putchar('0'+x%10);
}
const int maxn = 1e5+5;
const int maxm = 5e5+5;
int n,m,q;
struct edge{
    int u,v,w;
    bool operator < (const edge &y) const {
        return w < y.w;
    }
}e[maxm];
int father[maxn];
inline int find(int x) {
    int t = x;
    while(x != father[x]) x = father[x];
    int w;
    while(t != father[t]) w = father[t],father[t] = x,t = w;
    return x;
}
int v[maxn<<1],tot;
#define ls 0
#define rs 1
int f[maxn<<1][20],son[maxn<<1][2];
inline void kruskal() {
    sort(e+1,e+m+1);
    for (int i = 1; i <= m; i++) {
        int p = find(e[i].u),q = find(e[i].v);
        if (p != q) {
            ++tot;
            son[tot][0] = p,son[tot][1] = q;
            f[p][0] = f[q][0] = tot;
            v[tot] = e[i].w;
            father[p] = q;
        }
    }
}
inline void prepare() {
    for (int i = 1; i <= __lg(n); i++) {
        for (int j = 1; j <= tot; j++) {
            f[j][i] = f[f[j][i-1]][i-1];
        }
    }
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(n),read(m),read(q);
    tot = n;
    for (int i = 1; i <= 2*n; i++) father[i] = i;
    for (int i = 1; i <= m; i++)  read(e[i].u),read(e[i].v),read(e[i].w);
    kruskal();
    prepare();
    
    return 0;
}