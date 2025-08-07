#include <bits/stdc++.h>

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
    putchar(x%10+'0');
}
const int maxn = 50004;
int k,n,c,ans;
struct line{
    int l,r,v;
    bool operator < (const line &y) const{
        return r < y.r;
    }
}l[maxn];
int main () {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(k),read(n),read(c);
    for (int i = 1; i <= k; i++) {
        read(l[i].l),read(l[i].r),read(l[i].v);
    }
    sort(l+1,l+k+1);

    while (c--) {
        int ed = 0;
        for (int i = 1; i <= k; i++) {
            if (l[i].v == 0 || l[i].l < ed) continue;
            ed = l[i].r,++ans,l[i].v--;
        }
    }
    write(ans);
    return 0;
}