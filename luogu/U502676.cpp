#include <bits/stdc++.h>
#define ls p<<1
#define rs p<<1|1
using namespace std;
const int maxn = 2e6+30;
int n,m;
int val[maxn<<2];
inline void read(int &x) {
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
char buf[102];int top;
inline void write(int v) {
    top=0;
    while (v) buf[++top]=v%10+'0',v/=10;
    while (top) putchar(buf[top]),--top;
}
int a[maxn];
inline void pushup(int p) {
    val[p] = max(val[ls],val[rs]);
}
inline void build(int p,int l,int r) {
    if (l == r) {
        val[p] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    if (l <= mid) build(ls,l,mid);
    if (r > mid) build(rs,mid+1,r);
    pushup(p);
}
inline int query(int p,int s,int e,int v,int l,int r) {
    if (l == r) {
        if (val[p] <= v) return -1;
        else return l;
    }
    int mid = (l + r) >> 1;
    int ret = -1;
    if (s <= mid && val[ls] > v) ret = query(ls,s,e,v,l,mid);
    if (ret == -1 && e > mid) ret = query(rs,s,e,v,mid+1,r);
    return ret;
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(n),read(m);
    for (int i = 1; i <= n; i++) {
        read(a[i]);
    }
    build(1,1,n);
    for (int i = 1; i <= m; i++) {
        int l,r,k;
        read(l),read(r),read(k);
        printf("%d",query(1,l,r,k,1,n));
        putchar('\n');
    }
    return 0;
}