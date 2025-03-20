#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e6+40;
int n,maxx,ans;
int a[maxn],sum[maxn];
vector<int> b[maxn];
signed main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (b[a[i]].size() == 0) ++sum[i];
        sum[i] += sum[i-1];
        b[a[i]].push_back(i),maxx=max(maxx,a[i]);
    }
    for (int i = 1; i <= maxx; i++) {
        if (b[i].size() <= 1) continue;
        ans += sum[b[i][b[i].size()-2]]-1;
    }
    cout << ans << '\n';
    return 0;
}