#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x) {
    x = 0;int f = 1;char ch=getchar();
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
int a[maxn];
struct str{
    int val,id;
    bool operator < (const str &y) const{
        if (val == y.val) return id < y.id;
        return val < y.val;
    }
}b[maxn];
int t[3][maxn];
inline int lowbit(int &x) {
    return x&-x;
}
inline void modify(int p,int x,int cnt) {
    while (p <= n) {
        t[cnt][p] += x;
        p += lowbit(p);
    }
}
inline int query(int p,int cnt) {
    int ret = 0;
    while (p > 0) {
        ret += t[cnt][p];
        p -= lowbit(p);
    }
    return ret;
}
long long ans = 1;
int main() {
#ifdef LOCAL
    freopen("E:/OI/exe/a.in","r",stdin);
    freopen("E:/OI/exe/a.out","w",stdout);
#endif
    read(n);
    for (int i = 1; i <= n; i++) read(a[i]),b[i]={a[i],i};
    sort(b+1,b+n+1);
    for (int i = 1; i <= n; i++) {
        a[b[i].id] = i;
    }
    for (int i = 1; i <= n; i++) {
        modify(a[i],1,1);
        ans = max(ans,1ll*i-query(i,1));
    }
    printf("%lld",ans);
    return 0;
}