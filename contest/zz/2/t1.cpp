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
    putchar(x%10+'0');
}
const int maxn = 2004;
int n,m;
int mp[maxn][maxn];
int father[maxn*maxn],siz[maxn*maxn];
inline int g(int x,int y) {
    return (x-1)*m+y;
}
inline bool check(int x,int y) {
    return x>=1&&x<=n&&y>=1&&y<=m;
}
inline int find(int x) {
    int t = x;
    while (x != father[x]) x = father[x];
    int w;
    while (t != father[t]) w = father[t],father[t] = x,t = w;
    return x;
}
inline void merge(int x1,int y1,int x2,int y2) {
    int p = find(g(x1,y1)),q = find(g(x2,y2));
    if (p == q) return;
    father[p] = q;
    siz[q] += siz[p];
}
int vis[maxn*maxn];
int ans = 0x3f3f3f3f,tot = 0;
int main () {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
#ifndef LOCAL
    freopen("plague.in","r",stdin);
    freopen("plague.out","w",stdout);
#endif 
    read(n),read(m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) father[g(i,j)] = g(i,j),siz[g(i,j)] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char ch;cin >> ch;
            mp[i][j] = (ch=='1');
            if (mp[i][j] == 1) {
                ++tot;
                if (check(i-1,j)&&mp[i-1][j]==1) merge(i-1,j,i,j);
                if (check(i,j-1)&&mp[i][j-1]==1) merge(i,j-1,i,j);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mp[i][j] == 0) {
                int cnt = 0;
                if (check(i-1,j)&&mp[i-1][j]==1) {
                    int p = find(g(i-1,j));
                    if (vis[p] != g(i,j)) {
                        vis[p] = g(i,j);
                        cnt += siz[p];
                    }
                }
                if (check(i,j-1)&&mp[i][j-1]==1) {
                    int p = find(g(i,j-1));
                    if (vis[p] != g(i,j)) {
                        vis[p] = g(i,j);
                        cnt += siz[p];
                    }
                }
                if (check(i+1,j)&&mp[i+1][j]==1) {
                    int p = find(g(i+1,j));
                    if (vis[p] != g(i,j)) {
                        vis[p] = g(i,j);
                        cnt += siz[p];
                    }
                }
                if (check(i,j+1)&&mp[i][j+1]==1) {
                    int p = find(g(i,j+1));
                    if (vis[p] != g(i,j)) {
                        vis[p] = g(i,j);
                        cnt += siz[p];
                    }
                }
                ans = min(cnt,ans);
            }
        }
    }
    printf("%.9lf",1.0*(ans+1)/(tot+1));
    return 0;
}