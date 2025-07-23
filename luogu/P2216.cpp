#include <iostream>
#include <limits.h>
#include <cstring>
using namespace std;
const int maxn = 1003;
int qmax[maxn<<1],lmax,rmax,qmin[maxn<<1],lmin,rmin;
int fmax[maxn][maxn],fmin[maxn][maxn];
int gmax[maxn][maxn],gmin[maxn][maxn];
int a[maxn][maxn];
int n,m,t;
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    }
    for (int i = 1; i <= n; i++) {
        lmax = 1,rmax = 0;
        lmin = 1,rmin = 0;
        for (int j = 1; j <= m; j++) {
            while (lmax<=rmax&&qmax[lmax]<j-t+1) ++lmax;
            while (lmax<=rmax&&a[i][qmax[rmax]]<a[i][j]) --rmax;
            qmax[++rmax] = j;
            fmax[i][j] = a[i][qmax[lmax]];
            while (lmin<=rmin&&qmin[lmin]<j-t+1) ++lmin;
            while (lmin<=rmin&&a[i][qmin[rmin]]>a[i][j]) --rmin;
            qmin[++rmin] = j;
            fmin[i][j] = a[i][qmin[lmin]];
        }
        memset(qmax,0,sizeof(qmax));
        memset(qmin,0,sizeof(qmin));
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) cout << fmax[i][j] << ' ';
    //     cout << '\n';
    // }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) cout << fmin[i][j] << ' ';
    //     cout << '\n';
    // }
    for (int j = 1; j <= m; j++) {
        lmax = 1,rmax = 0;
        lmin = 1,rmin = 0;
        for (int i = 1; i <= n; i++) {
            while (lmax<=rmax&&qmax[lmax]<i-t+1) ++lmax;
            while (lmax<=rmax&&fmax[qmax[rmax]][j]<fmax[i][j]) --rmax;
            qmax[++rmax] = i;
            gmax[i][j] = fmax[qmax[lmax]][j];
            while (lmin<=rmin&&qmin[lmin]<i-t+1) ++lmin;
            while (lmin<=rmin&&fmin[qmin[rmin]][j]>fmin[i][j]) --rmin;
            qmin[++rmin] = i;
            gmin[i][j] = fmin[qmin[lmin]][j];
        }
        memset(qmax,0,sizeof(qmax));
        memset(qmin,0,sizeof(qmin));
    }
    int ans = INT_MAX;
    for (int i = t; i <= n; i++) {
        for (int j = t; j <= m; j++) {
            ans = min(ans,gmax[i][j]-gmin[i][j]);
        }
    }
    cout << ans << '\n';
    return 0;
}