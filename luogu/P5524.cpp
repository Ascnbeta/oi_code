#include <bits/stdc++.h>
#define ls p<<1
#define rs p<<1|1
using namespace std;
const int maxn = 1e6+50;
int n,m,q;
int op[maxn];
int val[maxn<<2],tim[maxn<<2],tagx[maxn<<2],tagt[maxn<<2];
inline void read(int& a) {
    int s = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
    s = s * 10 + ch - '0';
    ch = getchar();
    }
    a = s * w;
}
inline void read(long long &a) {
    int s = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
    s = s * 10 + ch - '0';
    ch = getchar();
    }
    a = s * w;
}
inline void pushdown(int p) {
    tim[ls] = tim[rs] = tagt[p];
    tagt[ls] = tagt[rs] = tagt[p];
    tagt[p] = 0;
    val[ls] = val[rs] = tagx[p];
    tagx[ls] = tagx[rs] = tagx[p];
    tagx[p] = 0;
}
inline void modify(int p,int s,int e,int v,int t,int l,int r) {
    if (s <= l && r <= e) {
        val[p] = v,tagx[p] = v;
        tim[p] = t,tagt[p] = t;
        return;
    }
    int mid = (l + r) >> 1;
    if (l != r && (tagx[p] || tagt[p])) pushdown(p);
    if (s <= mid) modify(ls,s,e,v,t,l,mid);
    if (e > mid) modify(rs,s,e,v,t,mid+1,r);
}
inline pair<int,int> query(int p,int pos,int l,int r) {
    if (val[p]) return val[p];
    if (l == r) {
        return {val[p],tim[p]};
    }
    int mid = (l + r) >> 1;
    if (l != r && (tagx[p] || tagt[p])) pushdown(p);
    return (pos<=mid)?(query(ls,pos,l,mid)):(query(rs,pos,mid+1,r));
}
int t[maxn],v[maxn];
struct ask{
    long long l,r,ans,id;
}a[maxn];
bool cmp1 (const ask &x,const ask &y) {
    return x.r < y.r;
}
bool cmp2 (const ask &x,const ask &y) {
    return x.id < y.id;
}
long long tr[maxn];
inline void modify(int p,int x) {
    if (p == 0) return;
    while (p <= m) {
        tr[p] += x;
        p += (p&-p);
    }
}
inline long long query(int p) {
    long long ret = 0;
    while (p > 0) {
        ret += tr[p];
        p -= (p&-p);
    }
    return ret;
}
void write(long long x) {
    static long long sta[66];
    int top = 0;
    do {
    sta[top++] = x % 10;
    x /= 10;
    } while (x);
    while (top) putchar(sta[--top] + '0');
}
signed main () {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    read(n),read(m),read(q);
    for (int i = 1 ; i <= m; i++) {
        read(op[i]);
        if (op[i] == 1) {
            int x,y;
            read(x),read(y);
            pair<int,int> t1 = query(1,x,1,n),t2 = query(1,y,1,n);
            modify(1,y,y,t1.first,t1.second,1,n);
            modify(1,x,x,t2.first,t2.second,1,n);
        }else if (op[i] == 2) {
            int l,r,x;
            read(l),read(r),read(x);
            modify(1,l,r,x,i,1,n);
        }else{
            int x;
            read(x);
            pair<int,int> tmp = query(1,x,1,n);
            v[i] = tmp.first,t[i] = tmp.second;
            if (t[i] == 0) op[i] = 0;
        }
    }
    for (int i = 1; i <= q; i++) read(a[i].l),read(a[i].r),a[i].id = i;
    sort(a+1,a+q+1,cmp1);
    int lst = 1;
    for (int i = 1; i <= m; i++) {
        while (a[lst].r <= i-1 && lst <= q) a[lst].ans = query(a[lst].r) - query(a[lst].l-1),++lst;
        if (op[i] == 3) {
            modify(t[i],v[i]);
        }
        while (a[lst].r <= i && lst <= q) a[lst].ans = query(a[lst].r) - query(a[lst].l-1),++lst;
    }
    sort(a+1,a+q+1,cmp2);
    for (int i = 1; i <= q; i++) write(a[i].ans),puts("");
    return 0;
}