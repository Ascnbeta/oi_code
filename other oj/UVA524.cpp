#include <bits/stdc++.h>
using namespace std;
int n,cnt = 1;
bool vis[20],pr[55] = {0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,0};
int ans[20];
void dfs(int x,int p) {
    vis[x] = true;
    ans[p] = x;
    if (p == n) {
        if (pr[x + ans[1]]) {
            for (int i = 1; i <= p; i++) {
                if (i == p) {
                    cout << ans[i];
                    break;
                }
                cout << ans[i] << ' ';
            }
            cout << '\n';
        }
        vis[x] = false;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        if (!pr[i+x]) continue;
        dfs(i,p+1);
    }
    vis[x] = false;
}
int main () {
    while (cin >> n) {
        if (cnt != 1) puts("");
        printf("Case %d:\n",cnt);
        dfs(1,1);
        ++cnt;
    }
    return 0;
}