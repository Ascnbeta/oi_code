#include <bits/stdc++.h>
#define ls p<<1
#define rs p<<1|1
using namespace std;
const int maxn = 5e5+10;
int n,m;
int a[maxn];
struct node{
    int max,lm,rm,sum;
}t[maxn<<2];
inline void pushup(int p) {
    t[p].sum = t[ls].sum + t[rs].sum;
    t[p].max = max(t[ls].max,t[rs].max);
    t[p].max = max(t[p].max,t[ls].rm+t[rs].lm);
    t[p].lm = max(t[ls].lm,t[ls].sum+t[rs].lm);
    t[p].rm = max(t[rs].rm,t[rs].sum+t[ls].rm);
}
void build(int p,int l,int r) {
    if (l == r) {
        t[p].max = t[p].lm = t[p].rm = t[p].sum = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(p);
}
void modify(int p,int v,int pos,int s,int e) {
    if (s == e) {
        t[p].max = t[p].lm = t[p].rm = t[p].sum = v;
        return;
    }
    int mid = (s + e) >> 1;
    if (pos <= mid) modify(ls,v,pos,s,mid);
    if (pos > mid) modify(rs,v,pos,mid+1,e);
    pushup(p);
}
node query(int p,int l,int r,int s,int e) {
    if (l <= s && e <= r) return t[p];
    int mid = (s + e) >> 1;
    if (l <= mid && r <= mid) {
        node t1 = query(ls,l,r,s,mid);
        return t1;
    }
    if (r > mid && l > mid) {
        node t2 = query(rs,l,r,mid+1,e);
        return t2;
    }
    if (l <= mid && r > mid) {
        node t1 = query(ls,l,r,s,mid),t2 = query(rs,l,r,mid+1,e);
        node t3;
        t3.sum = t1.sum + t2.sum;
        t3.max = max(t1.max,max(t2.max,t1.rm+t2.lm));
        t3.lm = max(t1.lm,t1.sum+t2.lm);
        t3.rm = max(t2.rm,t2.sum+t1.rm);
        return t3; 
    }
}
int main () {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1,1,n);
    cin >> m;
    while (m--) {
        int x,y;
        cin >> x >> y;
            if (x > y) swap(x,y);
            cout << query(1,x,y,1,n).max << '\n';
    }
    return 0;
}