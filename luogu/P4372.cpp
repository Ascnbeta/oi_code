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
const int maxn = 1e5+40;
int n;
struct element{
    int val,id;
}a[maxn];
bool cmp1 (const element &x,const element &y) {
    if (x.val == y.val) return x.id < y.id;
    return x.val < y.val;
}
bool cmp2 (const element &x,const element &y) {
    return x.id < y.id;
}
ll ans,t[maxn];
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(n);for (int i = 1; i <= n; i++) read(a[i].val),a[i].id=i;
    if (n == 1) {
        cout << 1 << '\n';
        return 0;
    }
    sort(a+1,a+n+1,cmp1);
    for (int i = 1; i <= n; i++) a[i].val = i;
    sort(a+1,a+n+1,cmp2);
    int k = n;
    for (int i = n; i >= 1; i--) {
        while (a[k].val > i) --k;
        t[i] = max(a[k].id - i,1);
    }
    for (int i = 0; i < n; i++) ans += max(t[i],t[i+1]);
    cout << ans << '\n';
    return 0;
}