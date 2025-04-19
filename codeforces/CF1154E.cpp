#include <bits/stdc++.h>
#define ls p<<1
#define rs p<<1|1
using namespace std;
const int maxn = 2e5+30;
int n;
int a[maxn];
int sum[maxn<<2],tag[maxn<<2];
inline void pushup(int p) {
    sum[p] = sum[ls] + sum[rs];
}
inline void pushdown(int p) {
    sum[ls] = sum[rs] = 0;
    tag[ls] = tag[rs] = 1;
    tag[p] = 0;
}
inline void build(int p,int l,int r) {
    if (l == r) {
        sum[p] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(p);
}
inline int query(int p,int s,int e,int l,int r) {
    if (s <= l && r <= e) {
        return sum[p];
    }
    int mid = (l + r) >> 1;
    if (l != r && tag[p]) pushdown(p);
    int ret = 0;
    if (s <= mid) ret += query(ls,s,e,l,mid);
    if (r > mid) ret += query(rs,s,e,mid+1,r);
    return ret; 
}
inline void modify(int p,int s,int e,int l,int r) {
    if (s <=)
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif

    return 0;
}