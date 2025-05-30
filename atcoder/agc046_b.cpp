#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 3e3+30;
const ll mod = 998244353;
int a,b,c,d;
ll f[maxn][maxn];
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> a >> b >> c >> d;
    f[a][b] = 1;
    for (int i = a+1; i <= c; i++) f[i][b] = f[i-1][b]*b%mod;
    for (int i = b+1; i <= d; i++) f[a][i] = f[a][i-1]*a%mod;
    for (int i = a+1; i <= c; i++) {
        for (int j = b+1; j <= d; j++) {
            f[i][j] = (f[i-1][j-1]*(i-1)%mod*(j-1)%mod+i+j-2+mod)%mod;
        }
    }
    cout << f[c][d] << '\n';
    return 0;
}