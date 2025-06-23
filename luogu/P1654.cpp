#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+30;
int n;
double p[maxn];
double f1[maxn],f2[maxn],f[maxn];
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) {
        f1[i] = (f1[i-1]+1)*p[i];
        f2[i] = (f2[i-1]+2*f1[i-1]*1+1)*p[i];
        f[i] = f[i-1]+(3*f2[i-1]+3*f1[i-1]+1)*p[i];
    }
    cout << fixed << setprecision(1) << f[n] << '\n';
    return 0;
}