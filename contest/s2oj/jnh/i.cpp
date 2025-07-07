#include <bits/stdc++.h>
#define int long long
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
const int maxn = 3e5+5;
int n,m;
struct node{
    ll s,a;
}p[maxn];
#define ls p<<1
#define rs p<<1|1
ll sum[maxn<<2],tags[maxn<<2],tagd[maxn<<2];
inline void pushup(int p) {
    sum[p] = sum[ls] + sum[rs];
}
inline void pushdown(int p,int l,int r) {
    int mid = (l + r) >> 1;
    sum[ls] += (tags[p]+tags[p]+1ll*(mid-l)*tagd[p])*1ll*(mid-l+1)/2;
    sum[rs] += (tags[p]+1ll*(mid-l+1)*tagd[p]+tags[p]+1ll*(r-l)*tagd[p])*1ll*(r-mid)/2;
    tags[ls] += tags[p];
    tagd[ls] += tagd[p];
    tags[rs] += tags[p]+1ll*(mid-l+1)*tagd[p];
    tagd[rs] += tagd[p];
    tags[p] = tagd[p] = 0;
}
inline void modify(int p,int lpos,int rpos,ll s,ll a,int l,int r) {
    if (lpos > rpos || lpos == 0 || rpos == 0) return;
    if (lpos <= l && r <= rpos) {
        sum[p] += (s+1ll*(l-lpos)*a+s+1ll*(r-lpos)*a)*1ll*(r-l+1)/2;
        tags[p] += s+1ll*(l-lpos)*a;
        tagd[p] += a;
        return;
    }
    int mid = (l + r) >> 1;
    if (l != r && (tags[p]||tagd[p])) pushdown(p,l,r);
    if (lpos <= mid) modify(ls,lpos,rpos,s,a,l,mid);
    if (rpos > mid) modify(rs,lpos,rpos,s,a,mid+1,r);
    pushup(p);
}
inline ll query(int p,int s,int e,int l,int r) {
    if (s <= l && r <= e) return sum[p];
    int mid = (l + r) >> 1;
    if (l != r && (tags[p]||tagd[p])) pushdown(p,l,r);
    ll ret = 0;
    if (s <= mid) ret += query(ls,s,e,l,mid);
    if (e > mid) ret += query(rs,s,e,mid+1,r);
    return ret;
}
inline void print(int p,int l,int r) {

    if (l == r) {
        cout << sum[p] << ' ';
        return;
    }
    int mid = (l + r) >> 1;
    if (l != r && (tags[p]||tagd[p])) pushdown(p,l,r);
    print(ls,l,mid);
    print(rs,mid+1,r);
}
signed main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(n),read(m);
    while (m--) {
        char op=getchar();
        if (op == 'P') {
            int pos;ll s,a;
            read(pos),read(s),read(a);
            int len = s / a;
            int l = pos - len;
            int r = pos - 1;
            l = max(1ll,l);
            r = min(n,r);
            modify(1,l,r,s-(pos-l)*a,a,1,n);
            l = pos + 1,r = pos + len;
            l = max(1ll,l);
            r = min(n,r);
            modify(1,l,r,s-a,-a,1,n);
            modify(1,pos,pos,s,0,1,n);
            p[pos] = {s,a};
        }else if(op == 'U') {
            int pos;read(pos);
            ll s = p[pos].s,a = p[pos].a;
            int len = s / a;
            int l = pos - len;
            int r = pos - 1;
            l = max(1ll,l);
            r = min(n,r);
            modify(1,l,r,-(s-(pos-l)*a),-a,1,n);
            l = pos + 1,r = pos + len;
            l = max(1ll,l);
            r = min(n,r);
            modify(1,l,r,-(s-a),a,1,n);
            modify(1,pos,pos,-s,0,1,n);
        }else if(op == 'Z') {
            int l,r;read(l),read(r);
            cout << 1ll*query(1,l,r,1,n)/(r-l+1) << '\n';
        }
        // print(1,1,n);
        // cout << '\n';
    }
    return 0;
}