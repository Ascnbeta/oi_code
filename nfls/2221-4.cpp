#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,cnt;
char s[203];
int f[203][103];
signed main () {
    #ifdef LOCAL
        freopen("D:/codes/exe/a.in","r",stdin);
        freopen("D:/codes/exe/a.out","w",stdout);
    #endif
    cin >> n >> m >> k;
    f[0][0] = 1;
    for (int i = 1; i <= n+m; i++) {
        f[i][0] = f[i-1][0];
        for (int j = 0; j <= n; j++) {
            f[i][j] = min(f[i-1][j]+f[i-1][j-1],k+1);
        }
    }
    if (f[n+m][n] < k) {
        puts("");
        return 0;
    }
    cnt = n;
    for (int i = 1; i <= n+m; i++) {
        if (cnt > 0 && f[n+m-i][cnt-1] >= k) {
            s[i] = 'a';
            --cnt;
        }else{
            s[i] = 'z';
            k -= f[n+m-i][cnt-1];
        }
    }
    for (int i = 1; i <= n+m; i++) {
        cout << s[i];
    }
    cout << '\n';
    return 0;
}