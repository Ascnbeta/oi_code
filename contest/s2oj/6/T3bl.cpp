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
template <typename T>
inline void write(T x) {
    if (x<0) putchar('-'),x=-x;
    if (x/10) write(x/10);
    putchar(x%10+'0');
}
const int maxn = 1e5+10;
int n;ll a,b;
ll x[maxn];
int rt;
const ll inf = 1000000000;
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/b.out","w",stdout);
#endif
    read(n),read(a),read(b);
    for (int i = 1; i <= n; i++) read(x[i]);
    for (int i = 1; i <= n; i++) {
        ll ans = LONG_LONG_MAX;
        for (int j = 1; j <= i; j++) {
            ll tmp1 = 0,tmp2 = 0;
            for (int k = 1; k <= i; k++) {
                if (x[k] < x[j]) tmp1 += x[j]-x[k];
                else if (x[k] > x[j]) tmp2 += x[k]-x[j];
            }
            ans = min(tmp1*a+tmp2*b,ans);
        }
        write(ans),putchar('\n');
    }
    return 0;
}