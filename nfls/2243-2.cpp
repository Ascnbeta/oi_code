#include <bits/stdc++.h>
typedef long long ll;
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
const int maxn = 3e5+10;
int n;
ll x,y;
ll f[maxn][2][2];
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(n);
    for (int i = 1; i <= n; i++) {
        read(x),read(y);
        if (x == 0) {
            f[i][0][1] = max(max(f[i-1][0][0],f[i-1][0][1]),max(f[i-1][1][0],f[i-1][1][1]))+y;
            f[i][0][0] = max(f[i-1][0][1],f[i-1][0][0]);
            f[i][1][1] = 0;
            f[i][1][0] = max(f[i-1][1][0],f[i-1][1][1]);
        }else{
            f[i][0][1] = 0;
            f[i][0][0] = max(f[i-1][0][0],f[i-1][0][1]);
            f[i][1][1] = max(f[i-1][0][0],f[i-1][0][1])+y;
            f[i][1][0] = max(f[i-1][1][1],f[i-1][1][0]);
        }
    }
    printf("%lld",max(max(f[n][0][0],f[n][0][1]),max(f[n][1][0],f[n][1][1])));
    return 0;
}