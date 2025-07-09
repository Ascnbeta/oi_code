#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
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
template <typename T>
inline void write(T x) {
    if (x<0) putchar('-'),x=-x;
    if (x/10) write(x/10);
    putchar(x%10+'0');
}
const int maxn = 1e5+10;
int n;ll a,b;
ll x[maxn];
struct node{
    ll val;int ls,rs,cnt;
}t[4000005];int tot;
inline void pushup(int p) {
    t[p].val = t[t[p].ls].val + t[t[p].rs].val;
    t[p].cnt = t[t[p].ls].cnt + t[t[p].rs].cnt;
}
inline void modify(int &p,int pos,int l,int r) {
    if (!p) p = ++tot;
    if (l == r) {
        t[p].val += l;
        t[p].cnt++;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) modify(t[p].ls,pos,l,mid);
    else modify(t[p].rs,pos,mid+1,r);
    pushup(p);
}
pair<ll,int> operator + (const pair<ll,int> &p,const pair<ll,int> &q) {
    return make_pair(p.first+q.first,p.second+q.second);
}
inline pair<ll,int> query(int p,int s,int e,int l,int r) {
    if (s > e) return {0,0};
    if (!p) return {0,0};
    if (s <= l && r <= e) return {t[p].val,t[p].cnt};
    int mid = (l + r) >> 1;
    pair<ll,int> ret = {0,0};
    if (s <= mid) ret = ret + query(t[p].ls,s,e,l,mid);
    if (e > mid) ret = ret + query(t[p].rs,s,e,mid+1,r);
    return ret;
}
int rt;
const int inf = 1000000000;
ll maxv = 0;
set<int> s;
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    read(n),read(a),read(b);
    for (int i = 1; i <= n; i++) read(x[i]),maxv = max(maxv,x[i]);
    // ll siz = 0;
    ll maxx = 0,minn = LONG_LONG_MAX,ans = 0,r = 0;
    for (int i = 1; i <= n; i++) {
        maxx = max(maxx,x[i]);
        minn = min(minn,x[i]);
        modify(rt,x[i],1,maxv);
        s.insert(x[i]);
        if (s.size() == 1) r = *s.begin();
        else {
            auto it = s.lower_bound(r);
            auto it1 = --it;
            auto it2 = ++it;
            if (it == s.begin()) {
                r = *it2;
                pair<ll,int> ret1 = query(rt,1,r-1,1,maxv);
                pair<ll,int> ret2 = query(rt,r+1,maxv,1,maxv);
                ll tmp1 = (ret1.second*r-ret1.first)*a;
                ll tmp2 = (ret2.first-ret2.second*r)*b;
                ans = tmp1+tmp2;
            }
        }
        pair<ll,int> ret1 = query(rt,1,r-1,1,maxv);
        pair<ll,int> ret2 = query(rt,r+1,maxv,1,maxv);
        ll tmp1 = (ret1.second*r-ret1.first)*a;
        ll tmp2 = (ret2.first-ret2.second*r)*b;
        ans = tmp1+tmp2;
        write(ans),putchar('\n');
    }
    // calc = clock()-calc;
    // write(calc);
    return 0;
}