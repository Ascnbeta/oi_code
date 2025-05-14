#include <bits/stdc++.h>
#define int long long
#define ls p<<1
#define rs p<<1|1
using namespace std;
const int maxn = 2e5+30;
int c,T,n;
struct box{
    int a,b,t,id;
    bool operator < (const box &y) const{
        return t < y.t;
    }
}a[maxn];
inline int read() {
    int x = 0,f = 1; char ch;
    ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    x = x * f;
    return x;
}
struct node{
    int sum,max,min,tag;
}t[maxn<<2];
inline void pushup(int p){
    t[p].sum = t[ls].sum + t[rs].sum;
    t[p].max = max(t[ls].max,t[rs].max);
    t[p].min = min(t[ls].min,t[rs].min);
}
inline void pushdown(int p,int l,int r) {
    int mid = (l + r) >> 1;
    t[ls].sum = t[p].tag * (mid-l+1);
    t[rs].sum = t[p].tag * (r-mid);
    t[ls].max = t[rs].max = t[ls].min = t[rs].min = t[ls].tag = t[rs].tag = t[p].tag;
    t[p].tag = 0x3f3f3f3f;
}
inline void build(int p,int l,int r) {
    t[p].tag = 0x3f3f3f3f;
    if (l == r) {
        if (l == 0) t[p].sum = t[p].min = t[p].max = -1;
        else if (l > n) t[p].sum = t[p].min = t[p].max = 1e9+30;
        else t[p].sum = t[p].max = t[p].min = a[l].a-l;
        return;
    }
    int mid = (l + r) >> 1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(p);
}
inline int query(int p,int s,int e,int l,int r) {
    if (s <= l && r <= e) return t[p].sum;
    int mid = (l + r) >> 1;
    if (l != r && t[p].tag != 0x3f3f3f3f) pushdown(p,l,r);
    int ret = 0;
    if (s <= mid) ret += query(ls,s,e,l,mid);
    if (e > mid) ret += query(rs,s,e,mid+1,r);
    return ret;
}
inline int getl(int p,int v,int l,int r) {
    if (l == r) return l;
    int mid = (l + r) >> 1;
    if (l != r && t[p].tag != 0x3f3f3f3f) pushdown(p,l,r);
    if (v <= t[rs].min) return getl(ls,v,l,mid);
    else return getl(rs,v,mid+1,r);
}
inline int getr(int p,int v,int l,int r) {
    if (l == r) return l;
    int mid = (l + r) >> 1;
    if (l != r && t[p].tag != 0x3f3f3f3f) pushdown(p,l,r);
    if (v < t[ls].max) return getr(ls,v,l,mid);
    else return getr(rs,v,mid+1,r);
}
inline void modify(int p,int s,int e,int v,int l,int r){
    if (s <= l && r <= e) {
        t[p].tag = v;
        t[p].max = t[p].min = v;
        t[p].sum = v * (r - l + 1);
        return;
    }
    int mid = (l + r) >> 1;
    if (l != r && t[p].tag != 0x3f3f3f3f) pushdown(p,l,r);
    if (s <= mid) modify(ls,s,e,v,l,mid);
    if (e > mid) modify(rs,s,e,v,mid+1,r);
    pushup(p);
}

signed main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    c = read(),T = read();
    while (T--) {
        n = read();
        
        for (int i = 1; i <= n; i++) a[i].a = read(),a[i].b = read(),a[i].t = read(),a[i].id = i;
        build(1,0,n+1);
        sort(a+1,a+n+1);
        int time = 0;bool f = true;
        for (int i = 1; i <= n; i++) {
            int pos = query(1,a[i].id,a[i].id,0,n+1)+a[i].id;
            if (pos == a[i].b) {
                if (time > a[i].t) {
                    f = false;
                    break;
                }
                continue;
            }
            if (pos > a[i].b) {
                int l = getl(1,a[i].b-a[i].id+1,0,n+1);
                int r = a[i].id-l-1;
                int tmp = query(1,l+1,a[i].id,0,n+1)+(l+1+a[i].id)*(a[i].id-l)/2;
                time += tmp-(2*a[i].b-r)*(r+1)/2;
                if (time > a[i].t) {
                    f = false;
                    break;
                }
                modify(1,l+1,a[i].id,a[i].b-a[i].id,0,n+1);
            }else{
                int l = getr(1,a[i].b-a[i].id-1,0,n+1);
                int r = l-a[i].id-1;
                int tmp = query(1,a[i].id,l-1,0,n+1)+(l-1+a[i].id)*(l-a[i].id)/2;
                time += (2*a[i].b+r)*(r+1)/2-tmp;
                if (time > a[i].t) {
                    f = false;
                    break;
                }
                modify(1,a[i].id,l-1,a[i].b-a[i].id,0,n+1);
            }

        }
        if (!f) {
            puts("No");
        }else{
            puts("Yes");
        }
    }
    return 0;
}