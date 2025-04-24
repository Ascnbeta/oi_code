#include <bits/stdc++.h>
#define ls p<<1
#define rs p<<1|1
using namespace std;
const int maxn = 1e5+30;
int n,k,ans;
int f[maxn][23][3];// 0>1 1>2 2>0
int sum1[maxn],sum2[maxn],sum0[maxn];
inline void print() {
    cout << '0' << '\n';
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            cout << f[i][j][0] << ' ';
        }
        cout << '\n';
    }
    cout << '1' << '\n';
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            cout << f[i][j][1] << ' ';
        }
        cout << '\n';
    }
    cout << '2' << '\n';
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            cout << f[i][j][2] << ' ';
        }
        cout << '\n';
    }
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        char ch;
        cin >> ch;
        if (ch == 'P') {
            sum2[i] = 1;
        }else if(ch == 'H') {
            sum0[i] = 1;
        }else{
            sum1[i] = 1;
        }
    }
    if (sum0[1] == 1) {
        f[1][0][2] = 1;
        f[1][0][1] = f[1][0][0] = 0;
    }
    if (sum1[1] == 1) {
        f[1][0][0] = 1;
        f[1][0][1] = f[1][0][2] = 0;
    }
    if (sum2[1] == 1) {
        f[1][0][1] = 1;
        f[1][0][0] = f[1][0][2] = 0;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = k; j >= 0; j--) {
            if (j == 0) {
                f[i][j][0] = f[i-1][0][0]+sum1[i];
                f[i][j][1] = f[i-1][0][1]+sum2[i];
                f[i][j][2] = f[i-1][0][2]+sum0[i];
            }else{
                f[i][j][0] = max(f[i-1][j][0]+sum1[i],max(f[i-1][j-1][1]+sum1[i],f[i-1][j-1][2]+sum1[i]));
                f[i][j][1] = max(f[i-1][j][1]+sum2[i],max(f[i-1][j-1][2]+sum2[i],f[i-1][j-1][0]+sum2[i]));
                f[i][j][2] = max(f[i-1][j][2]+sum0[i],max(f[i-1][j-1][1]+sum0[i],f[i-1][j-1][0]+sum0[i]));
            }
        }
    }
    // print();
    for (int i = 0; i <= k; i++) {
        ans = max(max(ans,f[n][i][0]),max(f[n][i][1],f[n][i][2]));
    }
    cout << ans << '\n';
    return 0;
}