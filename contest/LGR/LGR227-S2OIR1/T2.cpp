#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5+20;
int n,m,k,cnt;
int a[maxn];
void dfs(int u,ll sum) {
    if (u == m) {
        a[m] = n-sum%n;
        for (int i = 1; i <= m; i++) cout << a[i] << ' ';
        cout << '\n';
        ++cnt;
        if (cnt == k) exit(0);
        return;
    }
    for (int i = 1; i <= n; i++) a[u]=i,dfs(u+1,sum+i);
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
#ifndef LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
#endif
    cin >> n >> m >> k;
    dfs(1,0);
    return 0;
}