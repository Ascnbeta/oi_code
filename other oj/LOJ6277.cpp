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
inline void write (T x) {
    if (x<0) putchar('-'),x=-x;
    if (x/10) write(x/10);
    putchar('0'+x%10);
}
const int maxn = 5e4+10;
const int B = 230;
int n;ll a[maxn],bel[maxn],tag[605];
inline void add(int l,int r,ll v) {
    int lpos = bel[l],rpos = bel[r];
    if (lpos == rpos) for (int i = l;i <= r; i++) a[i] += v;
    else {
        for (int i = bel[l]+1; i <= bel[r]-1; i++) tag[i] += v;
        for (int i = l; bel[i] == bel[l]; i++) a[i] += v;
        for (int i = r; bel[i] == bel[r]; i--) a[i] += v;
    }
}
inline ll query(int pos) {
    return a[pos]+tag[bel[pos]];
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(n);
    for (int i = 1; i <= n; i++) read(a[i]);
    for (int i = 1; i <= n; i++) bel[i] = (i-1)/B+1;
    for (int i = 1; i <= n; i++) {
        int op,l,r;ll c;
        read(op),read(l),read(r),read(c);
        if (op == 0) add(l,r,c);
        else write(query(r)),putchar('\n');
    }
    return 0;
}