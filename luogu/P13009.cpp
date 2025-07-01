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
const int maxn = 1e5+30;
int T;
int n;ll m;
ll a[maxn],cnt[maxn],ans;
ll f[maxn][3];
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(T);
    while (T--) {
        read(n),read(m);ans = 0;
        for (int i = 1; i <= n; i++) {
            read(a[i]);
            if (m/a[i]==a[i]) cnt[i] = -1,ans += a[i];
            else if (m/a[i]>a[i]) cnt[i] = 1,ans += m/a[i];
            else if (m/(m/a[i])>a[i]) cnt[i] = 2,ans += m/(m/a[i]);
            else cnt[i] = 0,ans += a[i];

        }
        for (int i = 0; i <= n; i++) f[i][0] = f[i][1] = f[i][2] = 0x3f3f3f3f;
        f[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= 2; j++) {
                for (int k = 0; k <= 2; k++) {
                    if (k==0&&(cnt[i]==1||cnt[i]==2)) continue;
                    if (k==1&&(cnt[i]==0||cnt[i]==2)) continue;
                    if (k==2&&(cnt[i]==1)) continue;
                    f[i][k] = min(f[i][k],f[i-1][j]+max(0,k-j));
                }
            }
        }
        write(ans),putchar(' '),write(min({f[n][0],f[n][1],f[n][2]})),putchar('\n');
    }
    return 0;
}