#include <bits/stdc++.h>
using namespace std;
const int maxn = 513;
int n;
struct zone{
    int l,r;
    bool operator < (const zone &y) const{
        if (r == y.r) return l < y.l;
        return r < y.r;
    }
}a[maxn];
inline void read(int &v) {
    int x = 0,f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    v = x*f;
    return;
}
inline void write(int x) {
    if (x/10) write(x/10);
    putchar(x%10+'0');
}
int f[maxn];
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(n);
    for (int i = 1; i <= n; i++) read(a[i].l);
    read(n);
    for (int i = 1; i <= n; i++) read(a[i].r);
    f[0] = 1;
    ++n;
    a[n].l = a[n].r = 0x3f3f3f3f;
    sort(a+1,a+n+1);
    for (int i = 1; i <= n; i++) {
        int maxl = 0;
        for (int j = i-1; j >= 0; j--) {
            if (a[j].r >= a[i].l) continue;
            if (a[j].r < maxl) break;
            maxl = max(a[j].l,maxl);
            // write(i),putchar(' ');write(maxl),putchar('\n');
            f[i] += f[j];
        }
    }
    // for (int i = 1; i <= n; i++) write(f[i]),putchar(' ');
    write(f[n]);
    return 0;
}