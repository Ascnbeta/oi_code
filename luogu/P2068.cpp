#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,w;
int a[100004];
struct node{
    int l,r,v;
}t[400004];
int tr_cnt = 1;
inline void pushup(int p) {
    t[p].v = t[t[p].l].v + t[t[p].r].v;
}
void build(int p,int l,int r) {
    t[p].l = ++tr_cnt;
    t[p].r = ++tr_cnt;
    if (l == r) {
        t[p].v = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(t[p].l,l,mid);
    build(t[p].r,mid+1,r);
    pushup(p);
}
void modify(int cur,int v,int s,int e,int p) {
    if (s == cur && e == cur) {
        t[p].v += v;
        return;
    }
    int mid = (s + e) / 2;
    if (mid >= cur) modify(cur,v,s,mid,t[p].l);
    if (mid < cur) modify(cur,v,mid+1,e,t[p].r);
    pushup(p);
}
int query(int l,int r,int s,int e,int p) {
    if (l <= s && r >= e) return t[p].v;
    int mid = (s + e) / 2;
    int sum = 0;
    if (l <= mid) sum += query(l,r,s,mid,t[p].l);
    if (r > mid) sum += query(l,r,mid+1,e,t[p].r);
    return sum;
}
signed main () {
    cin >> n >> w;
    build(1,1,n);
    while(w--) {
        char ch;
        int x,y;
        cin >> ch >> x >> y;
        if (ch == 'x') {
            modify(x,y,1,n,1);
        }else{
            cout << query(x,y,1,n,1) << '\n';
        }
    }
    return 0;
}