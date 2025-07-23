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
bool f[maxn];ll val[maxn];
int dx[5] = {0,1,0},dy[5] = {0,0,1};
inline bool check(ll x);
inline void dfs(int u,int v);
ll sum = 0;
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(h),read(w);
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) read(a[g(i,j)]),sum += a[g(i,j)];
    }
    for (int i = 1; i <= h+w-1; i++) read(p[i]);
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
inline bool check(ll x) {
    memset(f,0,sizeof(f));
    memset(val,0,sizeof(val));
    val[g(1,1)] = x+a[1]-p[1];
    dfs(1,1);
    if (f[g(h,w)]) return true;
    return false;
}
inline void dfs(int u,int v) {
    if (val[g(u,v)] < 0) return; 
    f[g(u,v)] = true;
    if (u==h&&v==w) {
        return;
    }
    
    for (int i = 1; i <= 2; i++) {
        int tx = u+dx[i],ty = v+dy[i];
        if (tx<1||tx>h||ty<1||ty>w||f[g(tx,ty)]) continue;
        val[g(tx,ty)] = val[g(u,v)] + a[g(tx,ty)] - p[g(tx,ty)];
        dfs(tx,ty);
    }
    f[g(u,v)] = false;
}

