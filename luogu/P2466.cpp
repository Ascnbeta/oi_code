#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const int maxn = 1e3+40;
int n,x0,s;
struct ball{
    int x,y,v;
    bool operator < (const ball &y) const {
        return x < y.x;
    }
}b[maxn];
int sum[maxn];
double f[maxn][maxn][2];
signed main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> x0;
    for (int i = 1; i <= n; i++) cin >> b[i].x;
    for (int i = 1; i <= n; i++) cin >> b[i].y;
    for (int i = 1; i <= n; i++) cin >> b[i].v;
    b[n+1] = {x0,0,0};
    sort(b+1,b+n+2);
    for (int i = 1; i <= n+1; i++) {
        sum[i] = sum[i-1] + b[i].v;
        if (b[i].x == x0 && b[i].y == 0 && b[i].v == 0) s = i;
    }
    for (int i = 1; i <= n+1; i++) {
        for (int j = 1; j <= n+1; j++) {
            f[i][j][0] = f[i][j][1] = -1e18;
        }
    }
    f[s][s][0] = f[s][s][1] = 0;
    for (int len = 2; len <= n+1; len++) {
        for (int i = 1; i+len-1 <= n+1; i++) {
            int j = i+len-1;
            f[i][j][0] = max(f[i+1][j][0]-(b[i+1].x-b[i].x)*(sum[i]+sum[n+1]-sum[j])+b[i].y,f[i+1][j][1]-(b[j].x-b[i].x)*(sum[i]+sum[n+1]-sum[j])+b[i].y);
            f[i][j][1] = max(f[i][j-1][0]-(b[j].x-b[i].x)*(sum[i-1]+sum[n+1]-sum[j-1])+b[j].y,f[i][j-1][1]-(b[j].x-b[j-1].x)*(sum[i-1]+sum[n+1]-sum[j-1])+b[j].y);
        }
    }
    cout << fixed << setprecision(3) << max(f[1][n+1][0],f[1][n+1][1])/(double)1000.0 << '\n';
    return 0;
}