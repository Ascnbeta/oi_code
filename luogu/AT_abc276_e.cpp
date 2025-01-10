#include <bits/stdc++.h>
using namespace std;
int h,w,fx,fy;
vector<vector<int>> mp;
vector<vector<bool>> vis;
int dx[5] = {0,0,0,1,-1};
int dy[5] = {0,1,-1,0,0};
void dfs(int x,int y,int cnt) {
    if (x == fx && y == fy && cnt != 0) {
        cout << "Yes" << endl;
        exit(0);
    }
    if (cnt != 0) vis[x][y] = true;
    for (int i = 1; i <= 4; i++) {
        int tx = x + dx[i],ty = y + dy[i];
        if (tx < 0 || tx > h - 1 || ty < 0 || ty > w - 1) continue;
        if (vis[tx][ty]) continue;
        if (mp[tx][ty] == 1) continue;
        if (cnt == 1 && tx == fx && ty == fy) continue;
        dfs(tx,ty,cnt+1);
        mp[tx][ty] = 1;
    }
    vis[x][y] = false;
}
int main () {
    cin >> h >> w;
    for (int i = 1; i <= h; i++) {
        vector<int> t;
        vector<bool> t2;
        for (int j = 1; j <= w; j++) {
            char ch;
            cin >> ch;
            if (ch == '#') {
                t.push_back(1);
            }else{
                t.push_back(0);
                if (ch == 'S') {
                    fx = i-1;
                    fy = j-1;
                }
            }
            t2.push_back(false);
        }
        mp.push_back(t);
        vis.push_back(t2);
    }
    dfs(fx,fy,0);
    cout << "No" << endl;
    return 0;
}