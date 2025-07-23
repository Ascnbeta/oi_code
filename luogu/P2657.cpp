#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll l,r;
ll f[24][24][2][2],v[23];
inline ll dfs(int pos,int pre,int up,int v0) {
    if (~f[pos][pre][up][v0]) return f[pos][pre][up][v0];
    else if (pos == 0) return f[pos][pre][up][v0] = 1;
    f[pos][pre][up][v0] = 0;
    ll minn = v0?1:0,maxx = up?v[pos]:9;
    for (int i = minn; i <= maxx; i++) {
        if (abs(i-pre)<2) continue;
        f[pos][pre][up][v0] += dfs(pos-1,i,up&&(i==maxx),0);
    }
    return f[pos][pre][up][v0];
}
inline ll calc(ll x) {
    if (x <= 9) return x;
    memset(f,-1,sizeof(f));
    int pos = 0;
    while (x) {
        v[++pos] = x%10,x /= 10;
    }
    ll ans = 0;
    ans += dfs(pos,11,1,1);
    for (int i = pos-1; i >= 1; i--) ans += dfs(i,11,0,1);
    return ans;
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> l >> r;
    cout << calc(r)-calc(l-1) << '\n';
    return 0;
}