#include <bits/stdc++.h>
using namespace std;
int n,m,k;
string s,t;
int f[2][500004];
int main () {
    cin >> k >> s >> t;
    n = s.size(),m = t.size();
    s = ' ' + s,t = ' ' + t;
    if (abs(n-m)>k) {
        puts("No");
        return 0;
    }
    if (n>m) swap(s,t),swap(n,m);
    for (int i = 0; i <= n; i++) f[0][i] = i;
    for (int i = 1; i <= m; i++) {
        f[i&1][0] = i;
        for (int j = max(1,i-k); j <= min(n,i+k); j++) {
            f[i&1][j] = min(f[(i-1)&1][j-1]+(s[j]!=t[i]),min(f[(i-1)&1][j]+1,f[i&1][j-1]+1));
        }
    }
    if (f[m&1][n] <= k) puts("Yes");
    else puts("No");
    return 0;
}