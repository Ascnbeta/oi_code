#include <bits/stdc++.h>
using namespace std;
const int maxn = 203;
const double pi = 3.14159265358979323846;
int n,m,q;
double ans = 0.0;
double a[maxn][maxn][2];
int f[maxn][maxn];
inline bool check (int x,int y) {
    return x >= 1 && x <= 2*n && y >= 1 && y <= 2*m;
}
inline bool is_border (int x,int y) {
    if (check(x,y) && (f[x][y] == 1 || f[x][y] == 4)) return true;
    if (check(x,y+1) && (f[x][y+1] == 2 || f[x][y+1] == 3)) return true;
    if (check(x+1,y) && (f[x+1][y] == 2 || f[x+1][y] == 3)) return true;
    if (check(x+1,y+1) && (f[x+1][y+1] == 1 || f[x+1][y+1] == 4)) return true;
    return false;
}
bool vis[maxn][maxn][2];
void dfs(int x,int y,int d) {
    vis[x][y][d] = true;
    ans += a[x][y][d];
    if (f[x][y] == 5 && !vis[x][y][d^1]) dfs(x,y,d^1);
    if (d == 0) {
        if (check(x-1,y) && !vis[x-1][y][1]) dfs(x-1,y,1);
        if ((f[x][y] == 2 || f[x][y] == 3 || f[x][y] == 5) && check(x,y-1)) {
            if ((f[x][y-1] == 1 || f[x][y-1] == 4 || f[x][y-1] == 5) && !vis[x][y-1][0]) dfs(x,y-1,0);
            if ((f[x][y-1] == 2 || f[x][y-1] == 3 || f[x][y-1] == 5) && !vis[x][y-1][1]) dfs(x,y-1,1);  
        }
        if ((f[x][y] == 1 || f[x][y] == 4 || f[x][y] == 5) && check(x,y+1)) {
            if ((f[x][y+1] == 2 || f[x][y+1] == 3 || f[x][y+1] == 5) && !vis[x][y+1][0]) dfs(x,y+1,0);
            if ((f[x][y+1] == 1 || f[x][y+1] == 4 || f[x][y+1] == 5) && !vis[x][y+1][1]) dfs(x,y+1,1);  
        } 
    }
    if (d == 1) {
        if (check(x+1,y) && !vis[x+1][y][0]) dfs(x+1,y,0);
        if ((f[x][y] == 2 || f[x][y] == 3 || f[x][y] == 5) && check(x,y+1)) {
            if ((f[x][y+1] == 2 || f[x][y+1] == 3 || f[x][y+1] == 5) && !vis[x][y+1][0]) dfs(x,y+1,0);
            if ((f[x][y+1] == 1 || f[x][y+1] == 4 || f[x][y+1] == 5) && !vis[x][y+1][1]) dfs(x,y+1,1);  
        }
        if ((f[x][y] == 1 || f[x][y] == 4 || f[x][y] == 5) && check(x,y-1)) {
            if ((f[x][y-1] == 1 || f[x][y-1] == 4 || f[x][y-1] == 5) && !vis[x][y-1][0]) dfs(x,y-1,0);
            if ((f[x][y-1] == 2 || f[x][y-1] == 3 || f[x][y-1] == 5) && !vis[x][y-1][1]) dfs(x,y-1,1);  
        } 
    }
}
int main () {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char s;
            cin >> s;
            if (s == '0') {
                a[2*i-1][2*j-1][0] = pi*0.25;
                a[2*i-1][2*j-1][1] = 1-pi*0.25;
                f[2*i-1][2*j-1] = 3;
                a[2*i-1][2*j][0] = 0.5;
                a[2*i-1][2*j][1] = 0.5;
                f[2*i-1][2*j] = 5;
                a[2*i][2*j-1][0] = 0.5;
                a[2*i][2*j-1][1] = 0.5;
                f[2*i][2*j-1] = 5;
                a[2*i][2*j][0] = 1-pi*0.25;
                a[2*i][2*j][1] = pi*0.25;
                f[2*i][2*j] = 2;
            }else{
                a[2*i-1][2*j-1][0] = 0.5;
                a[2*i-1][2*j-1][1] = 0.5;
                f[2*i-1][2*j-1] = 5;
                a[2*i-1][2*j][0] = pi*0.25;
                a[2*i-1][2*j][1] = 1-pi*0.25;
                f[2*i-1][2*j] = 4;
                a[2*i][2*j-1][0] = 1-pi*0.25;
                a[2*i][2*j-1][1] = pi*0.25;
                f[2*i][2*j-1] = 1;
                a[2*i][2*j][0] = 0.5;
                a[2*i][2*j][1] = 0.5;
                f[2*i][2*j] = 5;
            }
        }
    }
    cin >> q;
    while (q--) {
        int x,y;
        cin >> x >> y;
        ans = 0;
        memset(vis,0,sizeof(vis));
        if (is_border(x,y)) {
            printf("%.4f\n",ans);
            continue;
        }
        if (check(x,y) && !vis[x][y][1]) dfs(x,y,1);
        if (check(x+1,y) && !vis[x+1][y][0]) dfs(x+1,y,0);
        if (check(x,y+1) && !vis[x][y+1][1]) dfs(x,y+1,1);
        if (check(x+1,y+1) && !vis[x+1][y+1][0]) dfs(x+1,y+1,0);
        printf("%.4f\n",ans);
    }
    return 0;
}