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
const int maxn = 3e5+5;
int n,m;
struct node{
    ll s,a;
}p[maxn];
ll val[maxn];
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/b.out","w",stdout);
#endif
    read(n),read(m);
    while (m--) {
        char op=getchar();
        if (op == 'P') {
            int pos;ll s,a;
            read(pos),read(s),read(a);
            ll tmp = s - a;
            for (int i = pos-1; i >= 1 && tmp > 0; i--) val[i] += tmp,tmp -= a;
            tmp = s - a;
            for (int i = pos+1; i <= n && tmp > 0; i++) val[i] += tmp,tmp -= a;
            val[pos] += s;
            p[pos] = {s,a};
        }else if(op == 'U') {
            int pos;read(pos);
            ll s = p[pos].s,a = p[pos].a;
            ll tmp = s - a;tmp = -tmp;
            for (int i = pos-1; i >= 1 && tmp < 0; i--) val[i] += tmp,tmp += a;
            tmp = s - a;tmp = -tmp;
            for (int i = pos+1; i <= n && tmp < 0; i++) val[i] += tmp,tmp += a;
            val[pos] -= s;
        }else if(op == 'Z') {
            int l,r;read(l),read(r);ll sum = 0;
            for (int i = l; i <= r; i++) sum += val[i];
            cout << sum/(r-l+1) << '\n';
        }
        // for (int i = 1; i <= n; i++) cout << val[i] << ' ';
        // cout << '\n';
    }
    return 0;
}