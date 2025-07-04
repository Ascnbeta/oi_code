#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
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
const int maxn = 3e3+10;
int T;
int n,m;int v[13];
int f[maxn],g[maxn];
int a[maxn],b[maxn],w[maxn];
vector<int> ans;
struct node{
    int w,v;
    bool operator < (const node &y) const{
        return w < y.w;
    }
};
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(T);
    while (T--) {
        for (int i = 1; i <= 10; i++) read(v[i]);
        read(n),read(m);
        memset(f,0xc0,sizeof(f));
        f[0] = 0;
        for (int i = 1; i <= n; i++) {
            read(a[i]),read(b[i]);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (j >= a[i]) f[j] = max(f[j],f[j-a[i]]+b[i]);
            }
        }
        for (int i = 1; i <= m; i++) {
            if (f[i] > 0) f[i] = v[(f[i]*10-1)/i+1]*i;
        }
        memset(g,0,sizeof(g));
        g[0] = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j <= m; j++) {
                if (j >= i) g[j] = max(g[j],g[j-i]+f[i]);
            }
        }
        write(g[m]);putchar('\n');
    }   
    return 0;
}