#include <bits/stdc++.h>
#define ls p<<1
#define rs p<<1|1
using namespace std;
const int maxn = 1e5+30;
int n,m;
string s;
struct str{
    char ch;
    int pos,del;
    bool operator < (const str &y) const {
        return ch<y.ch;
    }
}s1[maxn];
int val[maxn<<2],maxx[maxn<<2];
inline void pushup(int p) { 
    maxx[p] = max(maxx[ls],maxx[rs]);
    val[p] = val[ls] + val[rs];
}
inline void build(int p,int l,int r) {
    if (l == r) {
        val[p] = 1,maxx[p] = l;
        return;
    }
    int mid = (l + r) >> 1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(p);
}
inline void modify(int p,int pos,int l,int r) {
    if (l == r) {
        val[p] = maxx[p] = 0;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) modify(ls,pos,l,mid);
    else modify(rs,pos,mid+1,r);
    pushup(p);
}
inline int querysum(int p,int s,int e,int l,int r) {
    if (s <= l && r <= e) {
        return val[p];
    }
    int mid = (l + r) >> 1;
    int ret = 0;
    if (s <= mid) ret += querysum(ls,s,e,l,mid);
    if (e > mid) ret += querysum(rs,s,e,mid+1,r);
    return ret;
}
inline int querymax(int p,int s,int e,int l,int r) {
    if (s <= l && r <= e) {
        return maxx[p];
    }
    int mid = (l + r) >> 1;
    int ret = s-1;
    if (s <= mid) ret = max(ret,querysum(ls,s,e,l,mid));
    if (e > mid) ret = max(ret,querysum(rs,s,e,mid+1,r));
    return ret;
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> m >> s;
    n = s.size();
    s = ' ' + s;
    for (int i = 1; i <= n; i++) {
        s1[i] = {s[i],i};
    }
    build(1,0,n+1);
    sort(s1+1,s1+n+1);
    char tmp = 0;
    for (int i = n; i >= 1; i--) {
        if (!tmp&&s1[i].ch != tmp) break;
        int l = max(0,s1[i].pos-m+1);
        int r = min(n+1,s1[i].pos+m-1);
        int ml = querymax(1,l,l+m-1,0,n+1);
    }
    return 0;
}