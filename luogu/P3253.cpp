#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 1e5+30;
int n,n1,n2,cur;ll ans;
int t[maxn],sum[maxn],idx[maxn],a[maxn],b[maxn];
inline int lowbit(int x) {
    return x&-x;
}
inline void modify(int p,int x) {
    while (p <= n) {
        t[p] += x;
        p += lowbit(p);
    }
}
inline int query(int p) {
    int ret = 0;
    while (p > 0) {
        ret += t[p];
        p -= lowbit(p);
    }
    return ret;
}
inline void init() {
    for (int i = 1; i <= n; i++) {
        t[i] = sum[i]-sum[i-lowbit(i)];
    }
}
inline void read(int &x) {
    x=0;int f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {
        if (ch=='-')f=-1;
        ch=getchar();
    }
    while (ch>='0'&&ch<='9') {
        x=(x<<3)+(x<<1)+(ch^48);
        ch=getchar();
    }
    x*=f;
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(n1),read(n2);
    n=n1+n2;
    for (int i = n1; i >= 1; i--) read(a[i]),b[i]=a[i];
    for (int i = n1+1; i <= n; i++) read(a[i]),b[i]=a[i];
    sort(b+1,b+n+1);
    for (int i = 1; i <= n; i++) {
        a[i]=lower_bound(b+1,b+n+1,a[i])-b;
        idx[a[i]]=i;
        sum[i] = sum[i-1]+1;
    }
    init();
    cur = n1;
    for (int i = n; i >= 1; i--) {
        if (idx[i] > cur) {
            ans += query(idx[i])-query(cur)-1;
            cur = idx[i];
            modify(idx[i],-1);
        }else if (idx[i] <= cur){
            ans += query(cur)-query(idx[i]-1)-1;
            cur = idx[i];
            modify(idx[i],-1);
        }
    }
    printf("%lld",ans);
    return 0;
}