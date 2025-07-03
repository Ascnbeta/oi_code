#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+10;
int n,m;
char mp[maxn][maxn];
pair<int,int> st[maxn];
int f[maxn][maxn],ans;
inline void solve(int s) {
    int top = 0;
    st[++top] = {f[s][1],1};
    for (int i = 2; i <= m; i++) {
        int cnt = 0;
        while (top&&st[top].first>=f[s][i]) {
            cnt += st[top].second;
            ans = max(ans,cnt*st[top--].first);
        }
        st[++top] = {f[s][i],cnt+1};
    }
    int cnt = 0;
    while (top) {
        cnt += st[top].second;
        ans = max(ans,cnt*st[top--].first);
    }
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mp[i][j];
            if (mp[i][j] == 'F') f[i][j] = f[i-1][j]+1;
        }
    }
    for (int i = 1; i <= n; i++) {
        solve(i);
    }
    cout << ans*3 << '\n';
    return 0;
}