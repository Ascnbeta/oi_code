#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 305;
const int mod = 1e9;
string s;
int n;
ll f[maxn][maxn];
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> s;
    n = s.size();
    s = " " + s;
    for (int i = 1; i <= n; i++) f[i][i] = 1;
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            if (s[i] != s[j]) continue;
            for (int k = i; k < j; k++) {
                if (s[i] == s[k]) {
                    f[i][j] = (f[i][j]+(f[i][k]*f[k+1][j-1]))%mod;
                }
            }
        }
    }
    cout << f[1][n] << '\n';
    return 0;
}