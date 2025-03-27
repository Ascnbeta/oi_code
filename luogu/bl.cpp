#include <bits/stdc++.h>
#define ls p<<1
#define rs p<<1|1
#define int long long
using namespace std;
const int maxn = 1e5+30;
int n,a,cf,cm,m,ans,minn = INT_MAX;
int g[maxn],g1[maxn];
void dfs(int cnt,int lft) {
	if (cnt == n+1 || lft == 0) {
		int cnt = 0;
		minn = INT_MAX;
    	for (int i = 1; i <= n; i++) {
        	minn = min(minn,g1[i]);
        	if (g1[i] == a) ++cnt;
    	}
		ans = max(ans,minn*cm+cnt*cf);
		return;
	}
	for (int i = g[cnt]; i <= min(a,lft+g[cnt]); i++) {
		g1[cnt] = i;
		dfs(cnt+1,lft-(i-g[cnt]));
		g1[cnt] = g[cnt];
	}
	
}
signed main() {
#ifdef LOCAL
    freopen("E:/codes/exe/a.in","r",stdin);
    freopen("E:/codes/exe/b.out","w",stdout);
#endif
    cin >> n >> a >> cf >> cm >> m;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> g[i];
        g1[i] = g[i];
        minn = min(minn,g[i]);
        if (g[i] == a) ++cnt;
    }
    sort(g+1,g+n+1,greater<int>());
    ans = cnt * cf + minn * cm;
	dfs(1,m);
    cout << ans << '\n';
    return 0;
}