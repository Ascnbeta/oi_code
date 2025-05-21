#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e3+3;
int n,m;
inline void read(int &v) {
    int x=0,f=1;
    char ch=getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') {
            f = -1;
        }
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x<<3)+(x<<1)+(ch^48);
        ch = getchar();
    }
    v=x*f;
}
inline void write(int x) {
    if (x<0) putchar('-'),x=-x;
    if (x/10) write(x/10);
    putchar(x%10+'0');
}
int a[maxn];
ll f[maxn],g[maxn];
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(n),read(m);
    for (int i = 1; i <= n; i++) read(a[i]);
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= a[i]; j--) {
            f[j] += f[j-a[i]];
            f[j] %= 10;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        memcpy(g,f,sizeof(g));
        for (int j = 1; j <= m; j++) {
            if (j>=a[i]) g[j] -= g[j-a[i]];
            g[j] = (g[j]+10)%10;
            write(g[j]);
        }
        
        putchar('\n');
    }
    return 0;
}