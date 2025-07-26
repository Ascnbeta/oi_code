#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x) {
    x=0;int f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {
        if (ch=='-') f=-1;
        ch=getchar();
    }
    while (ch>='0'&&ch<='9') {
        x=(x<<3)+(x<<1)+(ch^48);
        ch=getchar();
    }
    x*=f;
}
template <typename T>
inline void write(T x) {
    if (x<0) putchar('-'),x=-x;
    if (x/10) write(x/10);
    putchar('0'+x%10);
}
const int maxn = 1e3+4;
int n,m,a,b,c,d;
int x[maxn][maxn],sum[maxn][maxn],sum1[maxn][maxn];
int q[maxn<<1],l,r;
int g[maxn][maxn],f[maxn][maxn];
int ans;
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(n),read(m),read(a),read(b),read(c),read(d);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            read(x[i][j]);
            sum[i][j] = sum[i-1][j]+sum[i][j-1]+x[i][j]-sum[i-1][j-1];
        }
    }
    for (int i = c+1; i <= n; i++) {
        l = 1,r = 0;
        for (int j = d+1; j <= m; j++) {
            sum1[i][j] = sum[i][j] - sum[i-c][j] - sum[i][j-d] + sum[i-c][j-d];
            while (l<=r&&q[l]<j-(b-d-1)+1) ++l;
            while (l<=r&&sum1[i][q[r]]>sum1[i][j]) --r;
            q[++r] = j;
            g[i][j] = sum1[i][q[l]];
        }
    }
    for (int j = d+1; j <= m; j++) {
        l = 1,r = 0;
        for (int i = c+1; i <= n; i++) {
            while (l<=r&&q[l]<i-(a-c-1)+1) ++l;
            while (l<=r&&g[q[r]][j]>g[i][j]) --r;
            q[++r] = i;
            f[i][j] = g[q[l]][j];
        }
    }
    for (int i = a; i <= n; i++) {
        for (int j = b; j <= m; j++) {
            ans = max(ans,sum[i][j]-sum[i-a][j]-sum[i][j-b]+sum[i-a][j-b]-f[i-1][j-1]);
        }
    }
    write(ans);
    return 0;
}