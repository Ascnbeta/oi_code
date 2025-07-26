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
ll a,b;
ll f[20][2][2],g[20][2][2],v[20];
void dfs(int pos,int up,int v0,int tgt) {
    if (~f[pos][up][v0]) return;
    else if (pos == 0) return f[pos][up][v0] = 1,g[pos][up][v0] = 0,void();
    f[pos][up][v0] = 0,g[pos][up][v0] = 0;
    int minn = v0?1:0,maxx = up?v[pos]:9;
    for (int i = minn; i <= maxx; i++) {
        dfs(pos-1,up&&i==maxx,0,tgt);
        f[pos][up][v0] += f[pos-1][up&&i==maxx][0];
        if (i == tgt) {
            g[pos][up][v0] += f[pos-1][up&&i==maxx][0]+g[pos-1][up&&i==maxx][0];
        }else{
            g[pos][up][v0] += g[pos-1][up&&i==maxx][0];
        }
    }
    return;
}
inline ll calc(ll x,int tgt) {
    // if (x<=9&&tgt != 0) return 1;
    // else if (x<=9) return 0;
    memset(f,-1,sizeof(f));
    memset(g,-1,sizeof(g));
    int pos = 0;
    while (x) {
        v[++pos] = x%10;
        x /= 10;
    }
    dfs(pos,1,1,tgt);
    ll ret = g[pos][1][1];
    for (int i = pos-1; i >= 1; i--) dfs(i,0,1,tgt),ret += g[i][0][1];
    return ret;
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(a),read(b);
    for (int i = 0; i <= 9; i++) write(calc(b,i)-calc(a-1,i)),putchar(' ');
    return 0;
}