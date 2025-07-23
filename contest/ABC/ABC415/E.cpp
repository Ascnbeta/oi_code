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
    if (x<0) x=-x,putchar('-');
    if (x/10) write(x/10);
    putchar('0'+x%10);
}
const int maxn = 2e5+5;
int h,w;
ll a[maxn],p[maxn];
inline int g(int x,int y) {
    if (x<1||x>h||y<1||y>w) return 0;
    return (x-1)*w+y;
}
ll f[maxn];
inline bool check(ll x) {
    for (int i = 0; i <= h; i++) {
        for (int j = 0; j <= w; j++) f[g(i,j)] = -1000000000000000000ll;
    }
    f[1] = x+a[1]-p[1];
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (i==1&&j==1) continue;
            if (f[g(i-1,j)] >= 0) f[g(i,j)] = max(f[g(i,j)],f[g(i-1,j)]+a[g(i,j)]-p[i-1+j]);
            if (f[g(i,j-1)] >= 0) f[g(i,j)] = max(f[g(i,j)],f[g(i,j-1)]+a[g(i,j)]-p[i-1+j]);
        }
    }
    if (f[g(h,w)] >= 0) return true;
    return false;
}
ll sum = 0;
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(h),read(w);
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) read(a[g(i,j)]);
    }
    for (int i = 1; i <= h+w-1; i++) read(p[i]),sum += p[i];
    ll l = 0,r = sum,ans = r;
    while (l <= r) {
        ll mid = (l+r)/2;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    write(ans);
    return 0;
}