#include <bits/stdc++.h>
using namespace std;
const int maxn = 7540;
int n,a[maxn],b[maxn];
int f[maxn][maxn];
int ans[maxn],sum[maxn];
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i],sum[i] = sum[i-1] + (a[i] == b[i]);
    if (n == 1) {
        if (a[1] == b[1]) {
            cout << "1\n1\n";
        }else{
            cout << "0\n0\n";
        }
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        f[i][i] = (a[i] == b[i]);
        ans[sum[n]]++;
        if (i == n) break;
        if (a[i] == b[i+1]) ++f[i][i+1];
        if (a[i+1] == b[i]) ++f[i][i+1];
        ans[f[i][i+1]+sum[i-1]-sum[0]+sum[n]-sum[i+1]]++;
    }
    for (int len = 3; len <= n; len++) {
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            if (a[i] == b[j]) ++f[i][j];
            if (a[j] == b[i]) ++f[i][j];
            f[i][j] += f[i+1][j-1];
            ans[f[i][j]+sum[i-1]-sum[0]+sum[n]-sum[j]]++;
        }
    }
    for (int i = 0; i <= n; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}