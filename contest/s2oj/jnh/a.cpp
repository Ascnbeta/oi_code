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
const int maxn = 1e4+5;
int n,a[maxn];
int t[maxn];
inline int lowbit(int x) {
    return x&-x;
}
inline void modify(int p,int x) {
    while (p <= n) {
        t[p] += x;
        p += lowbit(p);
    }
}
inline ll query(int p) {
    ll ret = 0;
    while (p > 0) {
        ret += t[p];
        p -= lowbit(p);
    }
    return ret;
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    ll ans = 0;
    for (int i = n; i >= 1; i--) {
        ans += query(a[i]-1);
        modify(a[i],1);
    }
    cout << ans << '\n';
    return 0;
}