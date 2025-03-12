#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e5+30;
int n;
vector<int> e[maxn],w[maxn];
int ans = 0;
void dfs(int u,int fa,int cnt,int val) {
    if (cnt == 3) return ans = max(val,ans),void();
    for (int i = 0; i < e[u].size(); i++) {
        int v = e[u][i],W = w[u][i];
        if (v == fa) continue;
        dfs(v,u,cnt+1,val+W);
    }
}
signed main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int x,y;
        cin >> x >> y;
        e[i].push_back(x);
        e[x].push_back(i);
        w[i].push_back(y);
        w[x].push_back(y);
    }
    for (int i = 1; i <= n; i++) dfs(i,0,0,0);
    for (int i = 1; i <= n; i++) {
        if (e[i].size() >= 3) {
            sort(w[i].begin(),w[i].end(),greater<int>());
            ans = max(w[i][0]+w[i][1]+w[i][2],ans);
        }
    }
    cout << ans << '\n';
    return 0;
}