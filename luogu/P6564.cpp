#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int n;
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
struct node{
    int id,v;
    bool operator < (const node &y) const {
        if (id-v==y.id-y.v) return id < y.id;
        return id-v<y.id-y.v;
    }
}a[maxn];
int t[maxn*10];
inline int lowbit(int x) {
    return x&-x;
}
inline void modify(int p,int x) {
    while (p <= 1e6) {
        t[p] = max(t[p],x);
        p += lowbit(p);
    }
} 
inline int query(int p) {
    int ret = 0;
    while (p > 0) {
        ret = max(t[p],ret);
        p -= lowbit(p);
    }
    return ret;
}
int ans;
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(n);
    for (int i = 1; i <= n; i++) read(a[i].v),a[i].id=i;
    sort(a+1,a+n+1);
    for (int i = 1; i <= n; i++) {
        if(a[i].id - a[i].v < 0) continue;
        int tmp = query(a[i].v-1)+1;modify(a[i].v,tmp);
        ans = max(ans,tmp);
    }
    printf("%d",ans);
    return 0;
}