#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 5e3+10;
template <typename T>
inline void read(T &x) {
    x=0;int f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {
        if (ch=='-') f=-1;
        ch=getchar();
    }
    while (ch>='0'&&ch<='9') {
        x=(x<<3)+(x<<1)+(48^ch);
        ch=getchar();
    }
    x*=f;
}
int T;
int n,a[maxn];
ll f[100005][3],sum[100005][3],maxx,ans,cnt;
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(T);
    while (T--) {
        read(n);maxx=ans=cnt=0;
        for (int i = 1; i <= n; i++) read(a[i]);
        sort(a+1,a+n+1);
        for (int i = 1; i <= n; i++) {
            for (int j = i+1; j <= n; j++) {
                int tmp = max(2*a[j],a[n])-a[j]-a[i];
                int idx = upper_bound(a+1,a+i,tmp)-a;
                ans += i-idx;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}