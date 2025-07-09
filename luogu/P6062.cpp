#include <bits/stdc++.h>
using namespace std;
const int maxn = 2505;
int n,m,mp[53][53];
int totc,totr;
int bel[53][53][2];
vector<int> e[maxn];
int vis[maxn],match[maxn];
inline bool hungary(int u,int cur) {
    if (vis[u] == cur) return false;
    vis[u] = cur;
    for (auto v : e[u]) {
        if (!match[v] || hungary(match[v],cur)) {
            match[v] = u;
            return true;
        }
    }
    return false;
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char ch;cin >> ch;
            if (ch == '*') {
                mp[i][j] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int l = 1,r = 1; l <= m; ) {
            if (mp[i][l] == 1) {
                ++totc;
                bel[i][l][0] = totc;
                while (r < m && mp[i][r+1] == 1) ++r,bel[i][r][0] = totc;
            }
            l=++r;
        } 
    }
    for (int i = 1; i <= m; i++) {
        for (int l = 1,r = 1; l <= n; ) {
            if (mp[l][i] == 1) {
                ++totr;
                bel[l][i][1] = totr;
                while (r < n && mp[r+1][i] == 1) ++r,bel[r][i][1] = totr;
            }
            l=++r;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mp[i][j]) {
                e[bel[i][j][0]].push_back(totc+bel[i][j][1]);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= totc+totr; i++) {
        if (hungary(i,i)) ++ans;
    }
    cout << ans << '\n';
    return 0;
}