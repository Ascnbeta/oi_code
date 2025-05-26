#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e6+30;
ll f[maxn],g[maxn],ans;
int n;
string s;
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> s;
    s = " " + s;
    for (int i = 1; i <= n; i++) {
        g[i] = i-1;
        while (g[i] >= 1 &&s[g[i]]!=s[i]) g[i]=g[g[i]]-1;
        if (g[i] < 1) continue;
        f[i] = f[g[i]-1]+1;
        ans += f[i];
        
    }
    // for (int i = 1; i <= n; i++) cout << f[i] << ' ';
    // cout << '\n';
    cout << ans << '\n';
    return 0;
}