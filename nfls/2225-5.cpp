#include <bits/stdc++.h>
using namespace std;
const int maxn = 543;
int n;
int a[maxn];
int f[maxn][maxn],g[maxn][maxn];
inline void read(int &v) {
    int x = 0,f = 1;
    char ch = getchar();
    while(ch <'0'||ch>'9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while(ch>='0'&&ch<='9') {
        x = x*10+ch-'0';
        ch = getchar();
    }
    v = x*f;
    return;
}
inline void write(int x){
    if (x/10) write(x/10);
    putchar(x%10+'0');
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(n);
    memset(g,0x3f,sizeof(g));
    for (int i = 1; i <= n; i++) read(a[i]),f[i][i] = a[i],g[i][i] = 1;
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i+len-1 <= n; i++) {
            int j = i+len-1;
            for (int k = i; k < j; k++) {
                if (f[i][k]==f[k+1][j] && f[i][k] != 0) {
                    f[i][j] = f[i][k] + 1;
                }
            }
        }
    }
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i+len-1 <= n; i++) {
            int j = i+len-1;
            if (f[i][j] != 0) g[i][j] = 1;
            else {
                for (int k = i; k < j; k++) {
                    g[i][j] = min(g[i][j],g[i][k]+g[k+1][j]);
                }
            }
       }
    }
    write(g[1][n]);
    return 0;
}