#include <bits/stdc++.h>
using namespace std;
int n,m,k,sx,sy;
int mp[54][54];
int ans[54][54];

int opt[1003];//east->1 south->2 west->3 north->4
bool vis[54][54][1004];
void dfs(int x,int y,int cnt) {
    if (cnt == k+1) {
        ans[x][y] = 2;
        return;
    }
    vis[x][y][cnt] = true;
    switch (opt[cnt]) {
        case 1: {//east
            for (int i = y+1; i <= m; i++) {
                if (vis[x][i][cnt+1]) continue;
                if (mp[x][i]) break;
                dfs(x,i,cnt+1);
            }
            break;
        }
        case 2: {//south
            for (int i = x+1; i <= n; i++) {
                if (vis[i][y][cnt+1]) continue;
                if (mp[i][y]) break;
                dfs(i,y,cnt+1);
            }
            break;
        }
        case 3: {//west
            for (int i = y-1; i >= 1; i--) {
                if (vis[x][i][cnt+1]) continue;
                if (mp[x][i]) break;
                dfs(x,i,cnt+1);
            }
            break;
        }
        case 4: {//north
            for (int i = x-1; i >= 1; i--) {
                if (vis[i][y][cnt+1]) continue;
                if (mp[i][y]) break;
                dfs(i,y,cnt+1);
            }
            break;
        }
    }
}
int main() {
#ifdef LOCAL
    freopen("E:/codes/exe/a.in","r",stdin);
    freopen("E:/codes/exe/a.out","w",stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char x;
            cin >> x;
            if (x == '*') sx = i,sy = j;
            if (x == 'X') ans[i][j] = mp[i][j] = 1;
        }
    }
    cin >> k;
    for (int i = 1; i <= k; i++) {
        string tmp;
        cin >> tmp;
        if (tmp == "EAST") opt[i] = 1;
        else if (tmp == "SOUTH") opt[i] = 2;
        else if (tmp == "WEST") opt[i] = 3;
        else if (tmp == "NORTH") opt[i] = 4;
    }
    dfs(sx,sy,1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << (char)((ans[i][j]==0)?('.'):((ans[i][j]==1)?('X'):('*')));
        }
        cout << '\n';
    }
    return 0;
}