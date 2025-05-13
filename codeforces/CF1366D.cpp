#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+30;
const int maxa = 1e7+10;
int n,a;
int ans[maxn][2];
int minp[maxa],p[maxa],tot;
inline void eular() {
    for (int i = 2; i <= maxa; i++) {
        if (!minp[i]) minp[i] = ++tot,p[tot] = i;
        for (int j = 1; j <= minp[i] && p[j] * i <= maxa; j++) {
            minp[p[j]*i] = j;
        }
    }
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n;
    eular();
    for (int i = 1; i <= n; i++) {
        cin >> a;
        if (a == 1 || a == 2) {
            ans[i][0] = ans[i][1] = -1;
            continue;
        } 
        int tmp = 1;
        int x = p[minp[a]];
        while (a != 1 && a % x == 0) a /= x,tmp *= x;
        if (a == 1) ans[i][0] = ans[i][1] = -1;
        else ans[i][0] = tmp,ans[i][1] = a;
    }
    for (int i = 1; i <= n; i++) cout << ans[i][0] << ' ';
    cout << '\n';
    for (int i = 1; i <= n; i++) cout << ans[i][1] << ' ';
    return 0;
}