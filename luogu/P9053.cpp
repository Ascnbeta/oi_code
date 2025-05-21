#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e6+30;
int n;
int a[maxn];
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
int pos[maxn],l,r,len,ans;
signed main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(n);
    for (int i = 1; i <= n; i++) read(a[i]),pos[a[i]]=i;
    printf("%lld ",2*n+1);
    l = n+1;
    for (int i = n; i >= n/2; i--) {
        l = min(l,pos[i]);
        r = max(r,pos[i]);
        len = r-l+1;
        int lft = (n-i)*2+1-len;
        if (lft >= 0) {
            int tl = max(l-lft,1ll);
            int tr = min(r+lft,n);
            ans += max(tr-r+l-tl-lft+1,0ll);
        }
        if (i == n) continue;
        lft = (n-i)*2-len;
        if (lft >= 0) {
            int tl = max(l-lft,1ll);
            int tr = min(r+lft,n);
            ans += max(tr-r+l-tl-lft+1,0ll);
        }
    }
    printf("%lld",ans);
    return 0;
}