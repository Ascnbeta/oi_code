#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5e3+5;
int n,ans;
int sq[maxn*maxn*2];
inline void read(int &v) {
    int x=0,f=1;char ch=getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x<<3)+(x<<1)+(ch^48);
        ch = getchar();
    }
    v = x*f;
}
signed main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(n);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            sq[i*i+j*j]++;
        }
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            ans += sq[i*i-j*j];
        }
    }
    printf("%lld",ans);
    return 0;
}