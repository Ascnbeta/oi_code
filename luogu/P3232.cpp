#include <bits/stdc++.h>
using namespace std;
const int maxn = 504;
const int maxm = 125004;
const double eps = 1e-7;
int n,m;
int deg[maxn];
struct edge{
    int u,v;
    double g;
    bool operator < (const edge &y) const {
        return g > y.g;
    }
}e[maxm];
int e1[maxn][maxn];
double f[maxn],a[maxn][maxn],b[maxn];
inline void solve() {
    for (int i = 1; i < n; i++) {
        int r = i;
        // for (int j = i+1; j <= n; j++) {
        //     if (a[r][i] < a[j][i] && fabs(a[j][i]-0) > eps) r = j;
        // }//找到第 i 个未知数最大的系数方程编号，确保精度
        if (r != i) swap(a[i],a[r]);
        double tmp = a[i][i];
        // assert(tmp);
        for (int j = i; j <= n; j++) a[i][j] /= tmp; //对第 i 个方程除以第 i 个未知数系数，使之系数为 1
        for (int j = i+1; j < n; j++) {
            tmp = a[j][i];//剩余方程中第 i 个未知数的系数
            for (int k = i; k <= n; k++) {
                a[j][k] -= a[i][k] * tmp;//把第 i 个方程乘上 tmp 再减去来消去第 i 个未知数系数
            }
        }
    }
    f[n-1] = a[n-1][n];//第 n-1 个未知数已经解得
    for (int i = n-2; i >= 1; i--) {
        f[i] = a[i][n];//先赋值为该方程的等号右侧常数项
        for (int j = i+1; j < n; j++) f[i] -= f[j]*a[i][j];//减去已经解得的未知数乘上系数，由于上面已经把第 i 个方程的第 i 个未知数系数置为 1，所以剩余值就是答案
    }
}
double ans;
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    scanf("%d %d",&n,&m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d",&e[i].u,&e[i].v);
        e1[e[i].u][e[i].v]++,e1[e[i].v][e[i].u]++;
        ++deg[e[i].u],++deg[e[i].v];
    }
    a[1][n] = -1;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (j != i) a[i][j] = 1.0 * e1[j][i] / deg[j];
            else a[i][j] = -1;
            // cout << a[i][j] << ' ';
        }
        // cout << '\n';
    }
    
    solve();
    // cout << f[1] << '\n';
    for (int i = 1; i <= m; i++) {
        if (e[i].u != n) e[i].g += 1.00/deg[e[i].u]*f[e[i].u];
        if (e[i].v != n) e[i].g += 1.00/deg[e[i].v]*f[e[i].v];
    }
    sort(e+1,e+m+1);
    for (int i = 1; i <= m; i++) ans += 1.00*e[i].g*i;
    printf("%.3f",ans);
    return 0;
}