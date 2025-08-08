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
int dx[5] = {0,0,0,-1,1},dy[5] = {0,-1,1,0,0};
inline int g(int x,int y) {
    return (x-1)*m+y;
}
inline bool check(int x,int y) {
    return x>=1&&x<=n&&y>=1&&y<=m;
}
int ans = 0x3f3f3f3f,tot = 0,cnt = 0,tmp;
int vis[maxn][maxn];
void dfs(int x,int y) {
    vis[x][y] = tmp;
    ++cnt;
    for (int i = 1; i <= 4; i++) {
        int tx = x + dx[i],ty = y + dy[i];
        if (!check(tx,ty)||vis[tx][ty]==tmp||mp[tx][ty]==0) continue;
        dfs(tx,ty); 
    }
}
int main () {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/b.out","w",stdout);
#endif
#ifndef LOCAL
    freopen("plague.in","r",stdin);
    freopen("plague.out","w",stdout);
#endif 
    read(n),read(m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char ch;cin >> ch;
            mp[i][j] = (ch=='1');
            if (mp[i][j] == 1) ++tot;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mp[i][j] == 0) {
                cnt = 0;
                ++tmp;
                if (check(i-1,j)&&vis[i-1][j] != tmp&&mp[i-1][j] == 1) {
                    dfs(i-1,j);
                }
                if (check(i,j-1)&&vis[i][j-1] != tmp&&mp[i][j-1] == 1) {
                    dfs(i,j-1);
                } 
                if (check(i+1,j)&&vis[i+1][j] != tmp&&mp[i+1][j] == 1) {
                    dfs(i+1,j);
                }
                if (check(i,j+1)&&vis[i][j+1] != tmp&&mp[i][j+1] == 1) {
                    dfs(i,j+1);
                } 
                ans = min(ans,cnt);
            }
        }
    }
    printf("%.9lf",1.0*(ans+1)/(tot+1));
    return 0;
}