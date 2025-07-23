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
ll n,m;
struct node{
    ll a,b;
    bool operator < (const node &y) const{
        if (a-b==y.a-y.b) return a>y.a;
        return a-b<y.a-y.b;
    }
}s[maxn];
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(n),read(m);
    for (int i = 1; i <= m; i++) read(s[i].a),read(s[i].b);
    sort(s+1,s+m+1);
    ll ans = 0;
    for (int i = 1; i <= m; i++) {
        if (n >= s[i].a) {
            ll tmp = (n-s[i].a)/(s[i].a-s[i].b)+1;
            ans += tmp;
            n -= tmp*(s[i].a-s[i].b);
        }
    }
    write(ans);
    return 0;
}