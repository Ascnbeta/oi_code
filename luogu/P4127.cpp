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
    putchar('0'+x%10);
}
ll l,r,now;
ll f[25][170][170][2][2],v[25];
ll t[25];
ll dfs(int pos,int lft,int mod,int up,int v0) {
    if (lft < 0) return 0;
    if (~f[pos][lft][mod][up][v0]) return f[pos][lft][mod][up][v0];
    else if (pos == 0) return f[pos][lft][mod][up][v0] = (lft==0&&mod==0);
    f[pos][lft][mod][up][v0] = 0;
    int minn = v0?1:0,maxx = up?v[pos]:9;
    for (int i = minn; i <= min(maxx,lft); i++) {
        f[pos][lft][mod][up][v0] += dfs(pos-1,lft-i,(mod+i*t[pos-1]%now)%now,up&&i==maxx,0);
    }
    return f[pos][lft][mod][up][v0];
}
inline ll calc(ll x) {
    ll ret = 0;
    int pos = 0;
    while (x) {
        v[++pos] = x%10;
        x /= 10;
    }
    for (int i = 1; i <= 9*pos; i++) {
        memset(f,-1,sizeof(f));
        now = i;
        ret += dfs(pos,i,0,1,1);
        for (int j = pos-1; j >= 1; j--) ret += dfs(j,i,0,0,1);
    }
    return ret;
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(l),read(r);
    t[0] = 1;
    for (int i = 1; i <= 18; i++) t[i] = t[i-1]*10;
    write(calc(r)-calc(l-1));
    return 0;
}