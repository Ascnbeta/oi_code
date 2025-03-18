#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[30],p[102];
int f[(1<<24)],lft[(1<<24)];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int j = 1; j <= m; j++) cin >> p[j];
    sort(p+1,p+m+1,greater<int>());
    for (int i = 1; i < (1<<n); i++) f[i] = 0x3f3f3f3f;
    f[0] = 1,lft[0] = p[1];
    for (int i = 1; i < (1<<n); i++) {
        for (int j = 1; j <= n; j++) {
            if (i&(1<<(j-1))) {
                int t = i^(1<<(j-1));
                if (f[t] == 0x3f3f3f3f) continue;
                if (lft[t] >= a[j]) {
                    if (f[i] > f[t]) {
                        f[i] = f[t];
                        lft[i] = lft[t] - a[j];
                    }else if (f[i] == f[t]) {
                        if (lft[i] < lft[t] - a[j]) lft[i] = lft[t] - a[j];
                    }
                }else{
                    int cnt = f[t]+1;
                    if (p[cnt] < a[j]) {
                        continue;
                    }
                    if (f[i] > cnt && cnt <= m) {
                        f[i] = cnt;
                        lft[i] = p[f[i]] - a[j];
                    }else if(f[i] == cnt && cnt <= m) {
                        if (lft[i] < p[cnt] - a[j]) lft[i] = p[cnt] - a[j];
                    }
                }
            }
        }
    }
    if (f[(1<<n)-1] == 0x3f3f3f3f) puts("NIE");
    else cout << f[(1<<n)-1] << '\n';
    return 0;
}