#include <bits/stdc++.h>
using namespace std;
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
inline void write(int x) {
    if (x<0) putchar('-'),x=-x;
    if (x/10) write(x/10);
    putchar(x%10+'0');
}
const int maxn = 3e5+30;
const double alpha = 0.29;
int n,m,rt;int a[maxn];
int siz[maxn],val[maxn],tag[maxn],ls[maxn],rs[maxn],tot;
int st[maxn],len;
inline int create() {
    int p = len ? st[len--] : ++tot;
    siz[p] = 1,ls[p] = rs[p] = 0;
    return p;
}
inline void pushup(int p) {
    siz[p] = siz[ls[p]] + siz[rs[p]];
}
inline void pushdown(int p) {
    if (!tag[p]) return;
    tag[ls[p]] ^= 1,tag[rs[p]] ^= 1;
    swap(ls[ls[p]],rs[ls[p]]),swap(ls[rs[p]],rs[rs[p]]);
    tag[p] = 0;
}
inline void build(int &p,int l,int r) {
    p = create();
    if (l == r) {
        val[p] = l;return;
    }
    int mid = (l + r) >> 1;
    build(ls[p],l,mid),build(rs[p],mid+1,r);
    pushup(p);
}
inline int merge(int x,int y) {
    if (!x || !y) return x | y;
    int sum = siz[x] + siz[y];
    if (min(siz[x],siz[y]) >= alpha*sum) {
        int p = create();
        ls[p] = x,rs[p] = y;
        pushup(p);
        return p;
    }
    if (siz[x] >= siz[y]) {
        pushdown(x);
        if (siz[ls[x]] >= alpha*sum) {
            rs[x] = merge(rs[x],y);
            pushup(x);
            return x;
        }
        
        ls[x] = merge(ls[x],ls[rs[x]]);
        pushdown(rs[x]);
        int p = rs[x];
        rs[x] = merge(rs[rs[x]],y);
        st[++len] = p;
        pushup(x);
        return x;
    }else{
        pushdown(y);
        if (siz[rs[y]] >= alpha*sum) {
            ls[y] = merge(x,ls[y]);
            pushup(y);
            return y;
        }
        
        rs[y] = merge(rs[ls[y]],rs[y]);
        pushdown(ls[y]);
        int p = ls[y];
        ls[y] = merge(x,ls[ls[y]]);
        st[++len] = p;
        pushup(y);
        return y;
    }
}
inline void split(int p,int k,int &x,int &y) {
    if (!k) return x = 0,y = p,void();
    if (siz[p] == 1) {
        return x = p,y = 0,void();
    }
    pushdown(p);
    if (k >= siz[ls[p]]) {
        split(rs[p],k-siz[ls[p]],x,y);
        x = merge(ls[p],x);st[++len] = p;
    }else{
        split(ls[p],k,x,y);
        y = merge(y,rs[p]);st[++len] = p;
    }
}
inline void reverse(int l,int r) {
    int p1,p2,p3,p4;
    split(rt,l-1,p1,p2);
    split(p2,r-l+1,p3,p4);
    tag[p3] ^= 1;
    swap(ls[p3],rs[p3]);
    rt = merge(p1,merge(p3,p4));
}
inline void print(int p) {
    if (siz[p] == 1) return write(val[p]),putchar(' '),void();
    pushdown(p);
    print(ls[p]),print(rs[p]);
}
int main() {
#ifdef LOCAL
    freopen("E:/codes/exe/a.in","r",stdin);
    freopen("E:/codes/exe/a.out","w",stdout);
#endif
    read(n),read(m);
    build(rt,1,n);
    while (m--) {
        int l,r;
        read(l),read(r);
        reverse(l,r);
    }
    print(rt);
    return 0;
}