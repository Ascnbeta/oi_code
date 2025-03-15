#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e4+12;
const double alpha = 0.29;
int n,ans;
int val[maxn<<1],ls[maxn<<1],rs[maxn<<1],siz[maxn<<1],rt,tot;
inline int create(int v) {
    val[++tot] = v;
    siz[tot] = 1;
    ls[tot] = rs[tot] = 0;
    return tot;
}
inline void pushup(int p) {
    val[p] = val[rs[p]];
    siz[p] = siz[ls[p]] + siz[rs[p]];
}
inline int getval(int rnk) {
    int p = rt;
    while (1) {
        if (siz[p] == 1) return rnk == 1 ? val[p] : -1;
        if (rnk <= siz[ls[p]]) p = ls[p];
        else rnk -= siz[ls[p]],p = rs[p];
    } 
}
inline int getrank(int v) {
    int p = rt,cnt = 0;
    while (1) {
        if (siz[p] == 1) return cnt + 1;
        if (v <= val[ls[p]]) p = ls[p];
        else cnt += siz[ls[p]],p = rs[p];
    }
}
inline int getpre(int v) {//last < v
    return getval(getrank(v)-1);
}
inline int getnext(int v) {//first >= v
    return getval(getrank(v));
}
#define ch(x,d) ((d)?(rs[p]):(ls[x]))
inline void rotate(int p,int d) {
    swap(ls[p],rs[p]);
    swap(ls[ch(p,d^1)],rs[ch(p,d^1)]);
    swap(ch(ch(p,d^1),d^1),ch(p,d));
    pushup(ch(p,d^1));
    pushup(p);
}
inline void maintain(int p) {
    int d;
    if (siz[p] == 1) return;
    else if(siz[ls[p]] < alpha*siz[p]) d = 1;
    else if (siz[rs[p]] < alpha*siz[p]) d = 0;
    else return;
    if (siz[ch(ch(p,d),d^1)]*(1-alpha) >= siz[ch(p, d)]*(1-2*alpha)) rotate(ch(p,d),d^1);
    rotate(p,d);
}
inline void insert(int p,int v) {
    if (siz[p] == 1) {
        int x = create(val[p]),y = create(v);
        if (val[x]>val[y]) swap(x,y);
        ls[p] = x,rs[p] = y;
        pushup(p);
        return;
    }
    if (val[ls[p]] >= v) insert(ls[p],v);
    else insert(rs[p],v);
    pushup(p);
    maintain(p);
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n;
    rt = create(0x3f3f3f3f);
    insert(rt,-1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        int pr = getpre(x),nt = getnext(x);
        printf("debug:%d\n",i);
        cout << x << ' ' << pr << ' ' << nt << '\n';
        for (int i = 1; i <= tot; i++) {
            cout << i << ' ' << ls[i] << ' ' << rs[i] << ' ' << val[i] << ' ' << siz[i] << '\n';
        }
        if (i == 1) ans += x;
        else if (pr == -1) ans += nt-x;
        else if (nt == INT_MAX) ans += x-pr;
        else ans += min(nt-x,x-pr);
        insert(rt,x);
    }

    cout << ans << '\n';
    return 0;
}