#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
    if (x<0) x=-x,putchar('-');
    if (x/10) write(x/10);
    putchar(x%10+'0');
}
const int maxn = 1e6+5;
int n,q;
int x[maxn];
int f[maxn],g[maxn],ans[maxn];
int minn = 0x3f3f3f3f,maxx = 0;
int d = 0;
int main () {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
#ifndef LOCAL
    freopen("beacon.in","r",stdin);
    freopen("beacon.out","w",stdout);
#endif 
    read(n),read(q);
    for (int i = 1; i <= n; i++) {
        read(x[i]);
        f[x[i]]=g[x[i]]=x[i];maxx = max(maxx,x[i]),minn = min(minn,x[i]);
    }
    for (int i = minn; i <= maxx; i++) if (!g[i]) g[i] = g[i-1];
    for (int i = maxx; i >= minn; i--) if (!f[i]) f[i] = f[i+1];
    for (int k = 1; k <= 1e6; k++) {
        int l = minn,r = maxx;
        while (l < r) {
            if (l == g[min(l+k,maxx)] || r == f[max(r-k,minn)]) {
                ans[k] = -1;
                break;
            }
            l = g[min(l+k,maxx)],r = f[max(r-k,minn)];
            ++ans[k];
        }
    }
    while (q--) {
        int a;read(a),write(ans[a]),putchar(' ');
    }
    return 0;
}