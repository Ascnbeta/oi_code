#include <bits/stdc++.h>
#define int long long
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
    if (x<0) x=-x,putchar('-');
    if (x/10) write(x/10);
    putchar(x%10+'0');
}
const int maxn = 2e5+5;
int n,m,a[maxn],p[maxn],c[maxn];
long long t[maxn<<2],tag[maxn<<2];
inline int lowbit(int x) {
    return x&-x;
}
inline void modify(int p,int x) {
    while (p <= n) {
        t[p] += x;
        p += lowbit(p);
    }
}
inline int query(int p) {
    int ret = 0;
    while (p > 0) {
        ret += t[p];
        p -= lowbit(p);
    }
    return ret;
}
long long cf[maxn];
long long ans;
#define ls p<<1
#define rs p<<1|1
inline void pushup(int p) {
    t[p] = t[ls] + t[rs];
}
inline void pushdown(int p,int l,int r) {
    int mid = (l + r) >> 1;
    tag[ls] += tag[p],tag[rs] += tag[p];
    t[ls] += 1ll*tag[p]*(mid-l+1),t[rs] += 1ll*tag[p]*(r-mid);
    tag[p] = 0;
}
inline void modify(int p,int s,int e,int v,int l,int r) {
    if (s == 0 || e == 0 || s > e) return;
    if (s <= l && r <= e) {
        t[p] += 1ll*(r-l+1)*v;
        tag[p] += v;
        return;
    }
    int mid = (l + r) >> 1;
    if (l != r && tag[p]) pushdown(p,l,r);
    if (s <= mid) modify(ls,s,e,v,l,mid);
    if (e > mid) modify(rs,s,e,v,mid+1,r);
    pushup(p);
}
long long tmp[maxn];
inline void query(int p,int l,int r) {
    if (l == r) {
        tmp[l] = t[p];
        return;
    }
    int mid = (l + r) >> 1;
    if (l != r && tag[p]) pushdown(p,l,r);
    query(ls,l,mid);
    query(rs,mid+1,r);
}
signed main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(n);for (int i = 1; i <= n; i++) read(p[i]);
    read(m);for (int i = 1; i <= m; i++) read(a[i]);
    for (int i = 1; i <= n; i++) {
        c[i] = query(n)-query(p[i]);
        ans += c[i];
        modify(p[i],1);
    }
    int cur = 1;
    memset(t,0,sizeof(t));
    for (int i = 1; i <= m; i++) {
        while (cur <= n && cur <= a[i]) {
            // if (i>1) puts("Nagisa"),modifycf(1,c[cur]),modifycf(2,-c[cur]);
            // cout << cur << ' ' << querycf(1) << ' ' << querycf(2) << '\n';
            // if (c[cur] > 1) {
            //     modifycf(i,c[cur]-1);
            //     modifycf(i+1,-c[cur]+1);
            //     modifycf(i+1,-1);
            //     modifycf(i+c[cur]-1,1);
            // }
            // cout << cur << ' ' << querycf(1) << ' ' << querycf(2) << '\n';
            
            // cout<<"cur"<<p[cur]<<' '<<c[cur]<<'\n';
            if (!c[cur]) {
                ++cur;
                continue;
            }
            modify(1,i,min(i+c[cur]-1,m),1,1,m);
            ++cur;
        }
    }
    query(1,1,m);
    for (int i = 1; i <= m; i++) {
        ans -= tmp[i];
        write(ans),putchar('\n');
    }
    return 0;
}